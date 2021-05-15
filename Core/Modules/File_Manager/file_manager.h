/*
 * file_manager.h
 *
 *  Created on: Feb 4, 2021
 *      Author: emrei
 */

#ifndef MODULES_FILE_MANAGER_FILE_MANAGER_H_
#define MODULES_FILE_MANAGER_FILE_MANAGER_H_

#include "fatfs.h"

typedef struct __file_manager /* struct tag */
{
	FATFS drive_handler;
	FIL handler;
	FRESULT file_result;
	uint8_t disk_status;
	DIR direction;
	FILINFO info;
	char current_dir[256];
	uint32_t bytes_read;
	uint32_t bytes_write;
	size_t file_num;
} file_manager_t __attribute__((aligned));


#endif /* MODULES_FILE_MANAGER_FILE_MANAGER_H_ */
