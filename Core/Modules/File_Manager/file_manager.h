/*
 * file_manager.h
 *
 *  Created on: Feb 4, 2021
 *      Author: emrei
 */

#ifndef MODULES_FILE_MANAGER_FILE_MANAGER_H_
#define MODULES_FILE_MANAGER_FILE_MANAGER_H_
#include "fatfs.h"

#define	FILE_TEXT   (0)
#define	FILE_FOLDER (1)
#define	FILE_IMAGE  (2)

typedef struct __file_manager
{
	FATFS drive_handler;
	FIL file_handler;
	FRESULT file_result;
	uint8_t file_disk_status;
	DIR file_direction;
	FILINFO file_info;
	char file_rx_buffer[256];
	char file_current_dir[256];
	uint32_t file_bytes_read;
	uint32_t file_bytes_write;
	size_t file_counter;
}file_manager_t;



void File_Find_File(file_manager_t *file_manage,uint8_t file_type);

void File_Init(file_manager_t *file_manage);

void File_Deinit(file_manager_t *file_manage);

void File_Create_Dir(file_manager_t *file_manage, const TCHAR *dir);

void File_Get_Dir(file_manager_t *file_manage);

void File_Change_Dir(file_manager_t *file_manage,const TCHAR *dir);

void File_Get_Dir_2(file_manager_t *file_manage);

void File_Create_File(file_manager_t *file_manage, TCHAR *file_name);

void File_Read(file_manager_t *file_manage, TCHAR *file_name);

void File_Write(file_manager_t *file_manage, TCHAR *file_name,const char *data);

#endif /* MODULES_FILE_MANAGER_FILE_MANAGER_H_ */
