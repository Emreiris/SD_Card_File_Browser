/*
 * file_manager.hpp
 *
 *  Created on: 9 May 2021
 *      Author: emrei
 */

#pragma once

#include "fatfs.h"
#include <stdint.h>
#include <vector>


#define RX_BUF_SIZE (16)

typedef enum
{
	WRITE_MODE = 1,
	READ_MODE  = 2
}file_open_mode;

class file_attributes
{
public:
	FATFS drive_handler;
	FIL handler;
	FRESULT result;
	uint8_t disk_status;
	DIR direction;
	FILINFO info;
	char current_dir[256];
	uint8_t rx_buffer[RX_BUF_SIZE];
	uint32_t bytes_read;
	uint32_t bytes_write;
	size_t num;

};


class file_manager
{
public:


	file_manager();

	~file_manager();

	void search_files();

	void create_dir(TCHAR *dir);
	void change_dir(TCHAR *dir);
	void get_dir();

	void create_file();
	void open_file(file_open_mode mode);
	void close_file();
	void read_file();
	void write_file(TCHAR* data);

	void set_file_name(TCHAR *file_name);  /* getter function */
	TCHAR* get_file_name();                /* setter function */

private:
	TCHAR *file_name;
	file_attributes *file_handle = new file_attributes();

};


