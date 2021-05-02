/*
 * file_manager.cpp
 *
 *  Created on: 2 May 2021
 *      Author: emrei
 */
/*
 * file_manager.c
 *
 *  Created on: Feb 4, 2021
 *      Author: emrei
 */

#ifndef APPLICATION_FILE_MANAGER_FILE_MANAGER_C_
#define APPLICATION_FILE_MANAGER_FILE_MANAGER_C_

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
#include "file_manager.h"

/*
 * @variable definitions
 */

extern char SDPath[4];

class file_manager
{
public:

/*
 * @param  = pointer to file_manager_t
 * @retval = none.
 * @brief  = File system initialization that is compatible with SD card memory blocks.
 */

	file_manager()
	{
		MX_SDMMC1_SD_Init();
		MX_FATFS_Init();
		file_manage->file_result = f_mount(&file_manage->drive_handler, SDPath, 0);
		strncpy(file_manage->file_current_dir, SDPath, strlen(SDPath));
		Get_Dir();
		file_manage->file_result = f_opendir(&file_manage->file_direction, file_manage->file_current_dir);
		Get_Dir();

		Find_File();
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

	file_manage->file_result = f_readdir(&file_manage->file_direction, &file_manage->file_info);

	if( (file_manage->file_result != FR_OK) || (file_manage->file_info.fname[0] == '\0')  )
	{
		file_manage->file_counter = 0;
	}
	else
	{
		++file_manage->file_counter;
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
	strcat(file_manage->file_current_dir,"/");
	file_manage->file_result = f_mkdir(strcat(file_manage->file_current_dir, dir));

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

	strcat(file_manage->file_current_dir,"/");
	strcat(file_manage->file_current_dir, dir);

	file_manage->file_result = f_opendir(&file_manage->file_direction, file_manage->file_current_dir);

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

	strncpy(file_manage->file_current_dir, temp_buf, len);
}

/*
 * @param1  = pointer to file_manager_t
 * @param2  = file name that is desired to be created.
 * @retval = none.
 * @brief  = Creates new file in current direction.
 */

void Create_File(TCHAR *file_name)
{
	strcat(file_manage->file_current_dir,"\\");
	file_manage->file_result = f_open(&file_manage->file_handler, strcat(file_manage->file_current_dir, file_name), FA_CREATE_NEW);
	file_manage->file_result = f_close(&file_manage->file_handler);
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
	file_manage->file_result = f_open(&file_manage->file_handler, file_name, FA_READ);
	file_manage->file_result = f_read(&file_manage->file_handler,file_manage->file_rx_buffer, sizeof(file_manage->file_rx_buffer), (UINT *)file_manage->file_bytes_read);
	file_manage->file_result = f_close(&file_manage->file_handler);
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
	file_manage->file_result = f_open(&file_manage->file_handler, file_name, FA_OPEN_APPEND|FA_WRITE);
	file_manage->file_result = f_write(&file_manage->file_handler, data, strlen(data), (UINT *)file_manage->file_bytes_write);
	file_manage->file_result = f_close(&file_manage->file_handler);
}

private:
	file_manager_t *file_manage = new file_manager_t();


};
#endif /* APPLICATION_FILE_MANAGER_FILE_MANAGER_C_ */




