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

#if 0
/*
 * @variable definitions
 */

extern char SDPath[4];

FRESULT fres;

void File_Test()
{

	/* TODO: Test code will be written.*/
}

/*
 * @param  = pointer to file_manager_t
 * @retval = none.
 * @brief  = File system initialization that is compatible with SD card memory blocks.
 */

void File_Init(file_manager_t *file_manage)
{
	MX_SDMMC1_SD_Init();
	MX_FATFS_Init();
	file_manage->file_result = f_mount(&file_manage->drive_handler, SDPath, 0);

#if 0
	strncpy(file_manage->file_current_dir, SDPath, strlen(SDPath));
	File_Get_Dir(file_manage);
	file_manage->file_result = f_opendir(&file_manage->file_direction, file_manage->file_current_dir);
	File_Get_Dir(file_manage);

#endif

}

/*
 * @param  = pointer to file_manager_t
 * @retval = none.
 * @brief  = File system deinitialization that is compatible with SD card memory blocks.
 */

inline void File_Deinit(file_manager_t *file_manage)
{
	file_manage->file_result = f_mount(0, SDPath, 0);
}

/*
 * @param1  = pointer to file_manager_t
 * @retval  = none.
 * @brief   = Finds desired files in current direction. Stores file name in fil_info.
 */

void File_Find_File(file_manager_t *file_manage)
{

	file_manage->file_result = f_readdir(&file_manage->file_direction, &file_manage->info);

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

void File_Create_Dir(file_manager_t *file_manage,TCHAR *dir)
{
	File_Get_Dir(file_manage);
	strcat(file_manage->file_current_dir,"/");
	file_manage->file_result = f_mkdir(strcat(file_manage->file_current_dir, dir));

}

/*
 * @param1  = pointer to file_manager_t
 * @param2  = direction name that is desired to be changed.
 * @retval = none.
 * @brief  = Changes direction in current direction.
 */

void File_Change_Dir(file_manager_t *file_manage,TCHAR *dir)
{
	File_Get_Dir(file_manage);

	strcat(file_manage->file_current_dir,"/");
	strcat(file_manage->file_current_dir, dir);

	file_manage->file_result = f_opendir(&file_manage->file_direction, file_manage->file_current_dir);

	File_Get_Dir(file_manage);
}

/*
 * @param  = pointer to file_manager_t
 * @retval = none.
 * @brief  = Gets current direction.
 */

void File_Get_Dir(file_manager_t *file_manage)
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

void File_Create_File(file_manager_t *file_manage,TCHAR *file_name)
{
	strcat(file_manage->file_current_dir,"\\");
	file_manage->file_result = f_open(&file_manage->handler, strcat(file_manage->file_current_dir, file_name), FA_CREATE_NEW);
	file_manage->file_result = f_close(&file_manage->handler);
	File_Get_Dir(file_manage);
}

/*
 * @param1  = pointer to file_manager_t
 * @param2  = file name that is desired to be read.
 * @retval = none.
 * @brief  = Reads file in current direction if exist.
 */

void File_Read(file_manager_t *file_manage, TCHAR *file_name)
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

void File_Write(file_manager_t *file_manage, TCHAR *file_name,char *data)
{
	file_manage->file_result = f_open(&file_manage->handler, file_name, FA_WRITE| FA_OPEN_APPEND );
	file_manage->file_result = f_write(&file_manage->handler, data, strlen(data), (UINT *)file_manage->bytes_write);
	file_manage->file_result = f_close(&file_manage->handler);
}

#endif /* APPLICATION_FILE_MANAGER_FILE_MANAGER_C_ */

#endif
