/*
 * ui_components.cpp
 *
 *  Created on: 30 May 2021
 *      Author: emrei
 */

#include "ui_components.hpp"
#include "lvgl.h"

void ui_components::search_bar_create()
{
	file_search_ta = lv_textarea_create(this->get_screen());
	lv_obj_set_pos(file_search_ta, 5, 5);
	lv_obj_set_size(file_search_ta, lv_pct(98), lv_pct(15));
	lv_textarea_set_placeholder_text(file_search_ta, "Search file in here");
	lv_textarea_set_cursor_click_pos(file_search_ta, true);

}

void ui_components::search_bar_open()
{

}

void ui_components::file_list_create()
{
	file_list = lv_list_create(this->get_screen());
	lv_obj_set_pos(file_list, 5,2+lv_pct(15));
	lv_obj_set_size(file_list,lv_pct(98),lv_pct(85)-7);
}

void ui_components::file_list_search()
{

}

void ui_components::keyboard_create()
{

}

void ui_components::keyboard_handle()
{

}

lv_obj_t* ui_components::get_screen()
{
	return lv_scr_act();
}

void ui_components::set_screen(lv_obj_t* parent_screen)
{

}

