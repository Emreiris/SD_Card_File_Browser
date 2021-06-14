/*
 * main_window.cpp
 *
 *  Created on: 14 Haz 2021
 *      Author: emrei
 */

#include "main_window.hpp"

main_window::main_window()
{
	main_screen = lv_scr_act();
}

void main_window::create_window()
{
	this->file_list_create();
	this->search_file_create();
}

void main_window::search_file_create()
{
	file_search = lv_textarea_create(main_screen);
	lv_obj_set_pos(file_search, 5, 5);
	lv_obj_set_size(file_search, lv_pct(98), lv_pct(15));
	lv_textarea_set_placeholder_text(file_search, "Search file in here");
	lv_textarea_set_cursor_click_pos(file_search, true);
}

void main_window::file_list_create()
{
	file_list = lv_list_create(main_screen);
	lv_obj_set_pos(file_list, 5,2+lv_pct(15));
	lv_obj_set_size(file_list,lv_pct(98),lv_pct(85)-7);
}
