/*
 * file_manager.cpp
 *
 *  Created on: 2 May 2021
 *      Author: emrei
 */

/*
 * standart libs
 */

#include <string.h>
#include <stdio.h>
#include <string>
/*
 * costum libs
 */

#include "fatfs.h"
#include "sdmmc.h"
#include "file_manager.hpp"

/*
 * @variable definitions
 */

extern char SDPath[4];


void file_manager::file_manager_init()
{
	MX_SDMMC1_SD_Init();  /* Low level driver initalizations */
	MX_FATFS_Init();      /* File system initalizations */

	result = f_mount(&drive_handler, SDPath, 0);

	result = f_opendir(&direction, SDPath); /* simple workaround */

	strncpy(current_dir, SDPath, strlen(SDPath));
}


void file_manager::file_manager_deinit()
{
	f_mount(0, SDPath, 0);
}


void file_manager::search_files()
{
	static bool first_run = true;

	if(first_run == true )
	{
		/*aggresive searching for all files at current direction */
		result = f_findfirst(&direction, &info, current_dir,"*");
		first_run = false;

		if( (result == FR_OK) && (info.fname[0] != '\0') )
		{
			current_file_name = &info.fname[0]; //(current_file_name, &info.fname[0]);
			isfound = FILE_FOUND;
		}
		else
		{
			*current_file_name = '\0';
			isfound = FILE_NOTFOUND;
			first_run = true;
		}

		return;
	}

	if( isfound == FILE_FOUND )
	{
		f_findnext(&direction, &info);

		if( (result == FR_OK) && (info.fname[0] != '\0') )
		{
			current_file_name = &info.fname[0]; //strncpy(current_file_name, &info.fname[0], 30);
			isfound = FILE_FOUND;
		}
		else
		{
			*current_file_name = '\0';
			first_run = true;
			isfound = FILE_NOTFOUND;
		}
	}
}


void file_manager::create_file()
{
	result = f_open(&handler, strcat(strcat(current_dir, "/"), this->file_name), FA_CREATE_NEW);
	result = f_close(&handler);

	get_dir();
}


void file_manager::open_file(file_open_mode& mode)
{
	switch(mode)
	{
	case WRITE_MODE:
		result = f_open(&handler, file_manager::get_file_name(), FA_OPEN_APPEND|FA_WRITE);
		break;
	case READ_MODE:
		result = f_open(&handler, file_manager::get_file_name(), FA_READ);
		break;
	}
}


void file_manager::close_file()
{
	result = f_close(&handler);
}


void file_manager::read_file()
{
	result = f_read(&handler,rx_buffer, RX_BUF_SIZE, (UINT *)&bytes_read);
}


void file_manager::write_file(const char* data)
{
	result = f_write(&handler,(TCHAR *)data, strlen(data), (UINT *)&bytes_write);
}


void file_manager::create_dir(const char* dir)
{
	static char temp_buf[256]; /* waste of memory, I need to find a better way.*/

	get_dir();

	strncpy(temp_buf, current_dir, strlen(current_dir));

	result = f_mkdir(strcat(strcat(temp_buf, "/"), dir));
}


void file_manager::get_dir()
{
	static char temp_buf[256]; /* I am sure there is a better way that I could not see yet. */

	result = f_getcwd(temp_buf, UINT{0});

	strncpy(current_dir, temp_buf, strlen(temp_buf));
}


void file_manager::change_dir(const char* dir)
{
	get_dir();

	strcat(current_dir, "/");
	strcat(current_dir, dir);

	result = f_opendir(&direction, current_dir);

	get_dir();
}

