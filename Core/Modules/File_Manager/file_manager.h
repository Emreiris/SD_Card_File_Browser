/*
 * file_manager.h
 *
 *  Created on: Feb 4, 2021
 *      Author: emrei
 */

#ifndef MODULES_FILE_MANAGER_FILE_MANAGER_H_
#define MODULES_FILE_MANAGER_FILE_MANAGER_H_
#include "fatfs.h"


void find_text_file(void);


FRESULT File_Init(void);

FRESULT File_Deinit(void);

FRESULT File_Create_Dir(const TCHAR *dir);

FRESULT File_Get_Dir(void);

FRESULT File_Create(TCHAR *file_dir,char *file_name);

FRESULT File_Read(TCHAR *file_dir);

FRESULT File_Write(TCHAR *file_dir,const char *data);

#endif /* MODULES_FILE_MANAGER_FILE_MANAGER_H_ */
