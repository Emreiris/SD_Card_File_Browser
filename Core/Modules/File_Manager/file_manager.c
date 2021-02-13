/*
 * file_manager.c
 *
 *  Created on: Feb 4, 2021
 *      Author: emrei
 */

#ifndef APPLICATION_FILE_MANAGER_FILE_MANAGER_C_
#define APPLICATION_FILE_MANAGER_FILE_MANAGER_C_

#include "fatfs.h"
#include "sdmmc.h"
#include <string.h>
#include <stdio.h>
#include "file_manager.h"


extern char SDPath[4];

void File_Init(file_manager_t *file_manage)
{
	MX_SDMMC1_SD_Init();
	MX_FATFS_Init();
	file_manage->file_result = f_mount(&file_manage->drive_handler, SDPath, 0);
}


#if 0
file_manager_t find_text_file(void)
{

	size_t i = 0;
    fr = f_findfirst(&dj, &fno, "", "*.txt");  /* Start to search for photo files */

    while (fr == FR_OK && fno.fname[0])
    {         /* Repeat while an item is found */
        sprintf(&file_names[i][0], "%s\n", fno.fname);                /* Display the object name */
        fr = f_findnext(&dj, &fno); /* Search for next item */
        ++i;
    }

    f_closedir(&dj);
}
#endif

void File_Find_Text_File(file_manager_t *file_manage)
{

	static size_t  file_counter = 0;
	if( file_counter == 0 )
	{
		file_manage->file_result = f_findfirst(&file_manage->file_direction,&file_manage->file_info, "", "fil*.txt");

	}
	else if(( file_manage->file_result == FR_OK ) && ( file_manage->file_info.fname[0] ) && ( file_counter != 0))
	{
		file_manage->file_result = f_findnext(&file_manage->file_direction, &file_manage->file_info);

		if(( file_manage->file_result == FR_OK ) && ( file_manage->file_info.fname[0] ) )
		{
			file_counter = 0;
		}
	}

}

void File_Deinit(file_manager_t *file_manage)
{
	file_manage->file_result = f_mount(0, SDPath, 0);
}

void File_Create_Dir(file_manager_t *file_manage,const TCHAR *dir)
{
	file_manage->file_result = f_mkdir(dir);
}

void File_Change_Dir(file_manager_t *file_manage,const TCHAR *dir)
{
	file_manage->file_result = f_chdir(dir);
}

void File_Get_Dir(file_manager_t *file_manage)
{
	file_manage->file_result = f_getcwd(file_manage->file_current_dir, strlen(file_manage->file_current_dir));
}

void File_Create(file_manager_t *file_manage, TCHAR *file_dir,char *file_name)
{
	file_manage->file_result = f_open(&file_manage->file_handler, file_dir, FA_CREATE_NEW);

	file_manage->file_result = f_close(&file_manage->file_handler);
}

void File_Read(file_manager_t *file_manage, TCHAR *file_dir)
{
	file_manage->file_result = f_open(&file_manage->file_handler, file_dir, FA_READ);

	file_manage->file_result = f_read(&file_manage->file_handler,file_manage->file_rx_buffer, sizeof(file_manage->file_rx_buffer), (UINT *)file_manage->file_bytes_read);

	file_manage->file_result = f_close(&file_manage->file_handler);
}

void File_Write(file_manager_t *file_manage, TCHAR *file_dir,const char *data)
{
	file_manage->file_result = f_open(&file_manage->file_handler, file_dir, FA_OPEN_APPEND|FA_WRITE);

	file_manage->file_result = f_write(&file_manage->file_handler, data, strlen(data), (UINT *)file_manage->file_bytes_write);

	file_manage->file_result = f_close(&file_manage->file_handler);
}

#endif /* APPLICATION_FILE_MANAGER_FILE_MANAGER_C_ */
