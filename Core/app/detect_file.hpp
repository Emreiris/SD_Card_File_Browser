/*
 * detect_file.hpp
 *
 *  Created on: 15 Tem 2021
 *      Author: emrei
 */

#ifndef APP_DETECT_FILE_HPP_
#define APP_DETECT_FILE_HPP_

#include <map>
#include <stdint.h>

/* supported file extensions */
enum class file_types:int8_t
{
	TXT_FILE     = 1,
	BMP_FILE     = 2,
	BIN_FILE     = 3,
	FOLDER       = 4,  /* Not a file type but yeah Folder should be in this class. */
	UNKNOWN_FILE = -1
};


class detect_file
{
protected:

	const std::map<file_types, const char*> file_pairs = {
													     std::make_pair(file_types::BIN_FILE, ".bin"),
														 std::make_pair(file_types::BMP_FILE, ".bmp"),
														 std::make_pair(file_types::TXT_FILE, ".txt")
										                 };

	file_types current_file_type = file_types::UNKNOWN_FILE;

	void detect_file_type(std::string file_name);

};




#endif /* APP_DETECT_FILE_HPP_ */
