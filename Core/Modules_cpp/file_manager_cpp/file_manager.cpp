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


file_manager::file_manager()
{
	MX_SDMMC1_SD_Init();  /* Low level driver initalizations */
	MX_FATFS_Init();      /* File system initalizations */

	strncpy(file_handle->current_dir, SDPath, strlen(SDPath));
	file_handle->result = f_mount(&file_handle->drive_handler, SDPath, 0);
	get_dir();
	f_opendir(&file_handle->direction, file_handle->current_dir);
	get_dir();
}


file_manager::~file_manager()
{
	f_mount(0, SDPath, 0);
	delete file_handle;
}


void file_manager::search_files()
{
	file_handle->result = f_readdir(&file_handle->direction, &file_handle->info);

	if( (file_handle->result != FR_OK) || (file_handle->info.fname[0] == '\0')  )
	{
		file_handle->num = 0;
	}
	else
	{
		++file_handle->num = 0;
	}
}



void file_manager::set_file_name(TCHAR* file_name)
{
	this->file_name = file_name;
}



TCHAR* file_manager::get_file_name()
{
	return this->file_name;
}


void file_manager::create_file()
{
	strcat(file_handle->current_dir,"\\");
	strcat(file_handle->current_dir, this->file_name);

	file_handle->result = f_open(&file_handle->handler, file_handle->current_dir, FA_CREATE_NEW);
	file_handle->result = f_close(&file_handle->handler);

	get_dir();

}

void file_manager::open_file(file_open_mode mode)
{
	switch(mode)
	{
	case WRITE_MODE:
		file_handle->result = f_open(&file_handle->handler, file_manager::get_file_name(), FA_OPEN_APPEND|FA_WRITE);
		break;
	case READ_MODE:
		file_handle->result = f_open(&file_handle->handler, file_manager::get_file_name(), FA_READ);
		break;
	}

}



void file_manager::close_file()
{
	file_handle->result = f_close(&file_handle->handler);
}



void file_manager::read_file()
{
	file_handle->result = f_read(&file_handle->handler,file_handle->rx_buffer, RX_BUF_SIZE, (UINT *)file_handle->bytes_read);
}



void file_manager::write_file(TCHAR*  data)
{
	file_handle->result = f_write(&file_handle->handler,(TCHAR *)data, strlen(data), (UINT *)file_handle->bytes_write);
}


void file_manager::create_dir(TCHAR *dir)
{
	get_dir();
	strcat(file_handle->current_dir,"/");
	strcat(file_handle->current_dir, dir);
	file_handle->result = f_mkdir(file_handle->current_dir);
}

void file_manager::get_dir()
{
	memset(file_handle->current_dir, 0x00, sizeof(file_handle->current_dir));
	file_handle->result = f_getcwd(file_handle->current_dir, strlen(file_handle->current_dir));
}

void file_manager::change_dir(TCHAR* dir)
{

	get_dir(); /*just in case */
	strcat(file_handle->current_dir,"/");
	strcat(file_handle->current_dir, dir);

	file_handle->result = f_opendir(&file_handle->direction, file_handle->current_dir);

	get_dir();
}


#if 0
class file_manager
{
public:

/*
 * @param  = none.
 * @retval = none.
 * @brief  = File system initialization that is compatible with SD card memory blocks.
 */

	file_manager()
	{
		MX_SDMMC1_SD_Init();
		MX_FATFS_Init();
		file_manage->file_result = f_mount(&file_manage->drive_handler, SDPath, 0);
		strncpy(file_manage->current_dir, SDPath, strlen(SDPath));
		Get_Dir();
		file_manage->file_result = f_opendir(&file_manage->direction, file_manage->current_dir);
		Get_Dir();

	}

/*
 * @param  = pointer to file_manager_t
 * @retval = none.
 * @brief  = File system deinitialization that is compatible with SD card memory blocks.
 */

		~file_manager()
		{
			file_manage->file_result = f_mount(0, SDPath, 0);
		}


/*
 * @param1  = pointer to file_manager_t
 * @retval  = none.
 * @brief   = Finds desired files in current direction. Stores file name in fil_info.
 */

void Find_File()
{

	file_manage->file_result = f_readdir(&file_manage->direction, &file_manage->info);

	if( (file_manage->file_result != FR_OK) || (file_manage->info.fname[0] == '\0')  )
	{
		file_manage->file_num = 0;
	}
	else
	{
		++file_manage->file_num;
	}

}

/*
 * @param1  = pointer to file_manager_t
 * @param2  = direction name that is desired to be created.
 * @retval = none.
 * @brief  = Creates new direction for current direction. Creates folder to be spesific.
 */

void Create_Dir(TCHAR *dir)
{
	Get_Dir();
	strcat(file_manage->current_dir,"/");
	file_manage->file_result = f_mkdir(strcat(file_manage->current_dir, dir));

}

/*
 * @param1  = pointer to file_manager_t
 * @param2  = direction name that is desired to be changed.
 * @retval = none.
 * @brief  = Changes direction in current direction.
 */

void Change_Dir(TCHAR *dir)
{
	Get_Dir();

	strcat(file_manage->current_dir,"/");
	strcat(file_manage->current_dir, dir);

	file_manage->file_result = f_opendir(&file_manage->direction, file_manage->current_dir);

	Get_Dir();
}

/*
 * @param  = pointer to file_manager_t
 * @retval = none.
 * @brief  = Gets current direction.
 */

void Get_Dir()
{
	static TCHAR temp_buf[256];
	static UINT len  = 0;

	file_manage->file_result = f_getcwd(temp_buf, len);

	strncpy(file_manage->current_dir, temp_buf, len);
}

/*
 * @param1  = pointer to file_manager_t
 * @param2  = file name that is desired to be created.
 * @retval = none.
 * @brief  = Creates new file in current direction.
 */

void Create_File(TCHAR *file_name)
{
	strcat(file_manage->current_dir,"\\");
	file_manage->file_result = f_open(&file_manage->handler, strcat(file_manage->current_dir, file_name), FA_CREATE_NEW);
	file_manage->file_result = f_close(&file_manage->handler);
	Get_Dir();
}

/*
 * @param1  = pointer to file_manager_t
 * @param2  = file name that is desired to be read.
 * @retval = none.
 * @brief  = Reads file in current direction if exist.
 */

void Read(TCHAR *file_name)
{
	file_manage->file_result = f_open(&file_manage->handler, file_name, FA_READ);
	file_manage->file_result = f_read(&file_manage->handler,file_manage->file_rx_buffer, sizeof(file_manage->file_rx_buffer), (UINT *)file_manage->bytes_read);
	file_manage->file_result = f_close(&file_manage->handler);
}

/*
 * @param1  = pointer to file_manager_t
 * @param2  = file name that is desired to write data.
 * @param3  = char type data to write into file.
 * @retval  = none.
 * @brief   = Opens existing file and writes data.
 */

void Write(TCHAR *file_name,char *data)
{
	file_manage->file_result = f_open(&file_manage->handler, file_name, FA_OPEN_APPEND|FA_WRITE);
	file_manage->file_result = f_write(&file_manage->handler, data, strlen(data), (UINT *)file_manage->bytes_write);
	file_manage->file_result = f_close(&file_manage->handler);
}

private:
	file_manager_t *file_manage = new file_manager_t();


};
#endif



