/*
 * detect_file.cpp
 *
 *  Created on: 15 Tem 2021
 *      Author: emrei
 */

#include "detect_file.hpp"

void detect_file::detect_file_type(std::string file_name)
{
	if(file_name.find('.') == std::string::npos )
	{
		current_file_type = file_types::FOLDER;
		return;
	}

	for(const auto& [file_type, file_extent] : file_pairs)
	{

		if(file_name.find(file_extent) != std::string::npos )
		{
			current_file_type = file_type;
		}
		else
		{
			current_file_type = file_types::UNKNOWN_FILE;
		}
	}
}
