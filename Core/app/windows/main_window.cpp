/*
 * main_window.cpp
 *
 *  Created on: 14 Haz 2021
 *      Author: emrei
 */

#include "main_window.hpp"
#include "file_manager.hpp"

#include <map>
#include <string>
#include <algorithm>
#include <locale>

extern file_manager fm;

/* supported file extensions */
enum file_types
{

	BMP_FILE     = 2,
	UNKNOWN_FILE = 3,
	TXT_FILE     = 1
};

file_types current_file_type = file_types::UNKNOWN_FILE;

std::map<file_types, const char*> file_pairs = {{file_types::BMP_FILE, ".bmp"},
												{file_types::TXT_FILE, ".txt"}
									            };


static void detect_file_type(const char* file_name);



main_window::main_window()
{

}



void main_window::create_window()
{
	file_list_create();
	search_file_create();
}



void main_window::search_file_create()
{
	file_search = lv_textarea_create(get_screen());
	lv_obj_set_pos(file_search, 5, 5);
	lv_obj_set_size(file_search, lv_pct(98), lv_pct(15));
	lv_textarea_set_placeholder_text(file_search, "Search file in here");
	lv_textarea_set_cursor_click_pos(file_search, true);
}



void main_window::file_list_create()
{
	file_list = lv_list_create(get_screen());
	lv_obj_set_pos(file_list, 5,2+lv_pct(15));
	lv_obj_set_size(file_list,lv_pct(98),lv_pct(85)-7);
}



void main_window::refresh_file_list()
{

	do
	{
		fm.search_files();
		if(fm.isfound == FILE_NOTFOUND)
			break;

		list_button = lv_list_add_btn(file_list, LV_SYMBOL_FILE, fm.current_file_name);
		lv_obj_add_event_cb(list_button, button_event_handler, LV_EVENT_CLICKED, nullptr);
		lv_task_handler();
	}
	while(1);

}

void button_event_handler(lv_event_t * e)
{

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t*        obj = lv_event_get_target(e);
	if( code == LV_EVENT_CLICKED )
	{
		detect_file_type(lv_list_get_btn_text(NULL, obj));
	}

}

static void detect_file_type(const char* file_name)
{

	std::locale locale1, locale2;

	for(const auto& [file_type_enum, file_extent] : file_pairs)
	{
		if(strstr(file_name,file_extent))
		{
			current_file_type = file_type_enum;
		}
		else
		{
			current_file_type = file_types::UNKNOWN_FILE;
		}
	}

}

