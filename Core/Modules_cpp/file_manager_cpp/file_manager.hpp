/*
 * file_manager.hpp
 *
 *  Created on: 9 May 2021
 *      Author: emrei
 */

#pragma once

#include "fatfs.h"
#include <stdint.h>
#include <string>


#define RX_BUF_SIZE (16)

typedef enum
{
	WRITE_MODE = 1,
	READ_MODE  = 2
}file_open_mode;

typedef enum
{
	FILE_FOUND = 3,
	FILE_NOTFOUND = 4
}file_find;


class file_manager
{
public:
	uint8_t rx_buffer[RX_BUF_SIZE];
	char current_dir[256]; /* Long File Support */
	FRESULT result;
	FILINFO info;
	file_find isfound;
	char* current_file_name;

	void file_manager_init();
	void file_manager_deinit();

	void search_files();

	void create_dir(const char* dir);
	void change_dir(const char* dir);
	void get_dir();

	void create_file();
	void open_file(file_open_mode& mode);
	void close_file();
	void read_file();
	void write_file(const char* data);

	void set_file_name(std::string& file_name) { this->file_name = &file_name[0]; }
	char* get_file_name() { return this->file_name; }

private:
	FATFS drive_handler;
	FIL handler;
	uint8_t disk_status;
	DIR direction;

	char* file_name;
	uint32_t bytes_read;
	uint32_t bytes_write;

};


