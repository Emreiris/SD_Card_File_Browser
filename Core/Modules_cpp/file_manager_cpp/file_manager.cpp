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
	static bool process = false;

	if(process == false )
	{
		result = f_findfirst(&direction, &info, current_dir,
							 "*.txt");
		process = true;
		isfound = FILE_FOUND;
		return;
	}

	if( (result == FR_OK) and (info.fname[0] != '\0'))
	{
		isfound = FILE_FOUND;
		f_findnext(&direction, &info);
	}
	else
	{
		process = false;
		isfound = FILE_NOTFOUND;
	}



}


void file_manager::create_file()
{

	result = f_open(&handler, strcat(strcat(current_dir, "/"), this->file_name), FA_CREATE_NEW);
	result = f_close(&handler);

	get_dir();

}

void file_manager::open_file(file_open_mode mode)
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

	get_dir();

	static char temp_buf[256]; /* waste of memory, I need to find a better way.*/

	strncpy(temp_buf, current_dir, strlen(current_dir));

	result = f_mkdir(strcat(strcat(temp_buf, "/"), dir));

}

void file_manager::get_dir()
{

	static char temp_buf[256]; /* I am sure there is a better way that I could not see yet. */
	static UINT len = 0;

	result = f_getcwd(temp_buf, len);

	strncpy(current_dir, temp_buf, len);

}

void file_manager::change_dir(const char* dir)
{

	get_dir();
	strcat(current_dir, "/");
	strcat(current_dir, dir);

	result = f_opendir(&direction, current_dir);

	get_dir();
}



