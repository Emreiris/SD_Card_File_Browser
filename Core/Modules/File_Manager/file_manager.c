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

static FATFS drive_handler;
static FIL file_handler;
static char file_rx_buffer[256];
static char file_current_dir[256];

static uint32_t bytes_read;
static uint32_t bytes_write;

extern char SDPath[4];

char file_names[4][32];

#if 1
FRESULT fr;     /* Return value */
DIR dj;         /* Directory search object */
FILINFO fno;    /* File information */
#endif

FRESULT File_Init(void)
{
	MX_SDMMC1_SD_Init();
	MX_FATFS_Init();
	return f_mount(&drive_handler, SDPath, 0);
}

void find_text_file(void)
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



FRESULT File_Deinit(void)
{
	return f_mount(0, SDPath, 0);
}

FRESULT File_Create_Dir(const TCHAR *dir)
{
	return f_mkdir(dir);
}

FRESULT File_Change_Dir(const TCHAR *dir)
{
	return f_chdir(dir);
}

FRESULT File_Get_Dir(void)
{
	return f_getcwd(file_current_dir, strlen(file_current_dir));
}


FRESULT File_Create(TCHAR *file_dir,char *file_name)
{
	static FRESULT result;

	result = f_open(&file_handler, file_dir, FA_CREATE_NEW);

	result = f_close(&file_handler);

	return result;

}

FRESULT File_Read(TCHAR *file_dir)
{
	static FRESULT result;
	result = f_open(&file_handler, file_dir, FA_READ);

	result = f_read(&file_handler, (char *)file_rx_buffer, sizeof(file_rx_buffer), (UINT *)&bytes_read);

	result = f_close(&file_handler);
	return result;
}

FRESULT File_Write(TCHAR *file_dir,const char *data)
{
	static FRESULT result;

	result = f_open(&file_handler, file_dir, FA_OPEN_APPEND|FA_WRITE);

	result = f_write(&file_handler, data, strlen(data), (UINT *)&bytes_write);

	result = f_close(&file_handler);

	return result;
}

#endif /* APPLICATION_FILE_MANAGER_FILE_MANAGER_C_ */
