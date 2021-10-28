/*
 * main_window.cpp
 *
 *  Created on: 14 Haz 2021
 *      Author: emrei
 */

#include "main_window.hpp"

namespace gui
{

main_window::main_window()//:screen(lv_obj_create(NULL))
{
	screen = lv_obj_create(NULL);

	screen_width  = lv_obj_get_content_width(screen);
	screen_height = lv_obj_get_content_height(screen);

	create_text_input();
	create_search_button();
	//create_file_window();
	create_file_list();
	//create_keyboard();
}

void main_window::create_text_input()
{
	text_input = lv_textarea_create(screen);
	lv_textarea_set_placeholder_text(text_input, "Enter Filename");
	lv_textarea_set_max_length(text_input, 32);
	lv_obj_set_size(text_input, screen_width*0.72f, screen_height*0.15f);
	lv_obj_align(text_input, LV_ALIGN_TOP_LEFT, screen_width*0.03f, screen_height*0.03f);

}

void main_window::create_keyboard()
{
	keyboard = lv_keyboard_create(screen);
	lv_keyboard_set_textarea(keyboard, text_input);
}

void main_window::create_search_button()
{
	lv_style_t button_style;

	search_button = lv_btn_create(screen);
	lv_obj_set_size(search_button, screen_width*0.20f, screen_height*0.15f);
	lv_obj_align_to(search_button, text_input, LV_ALIGN_OUT_RIGHT_MID, 10, 0);

	lv_obj_t* label = lv_label_create(search_button);
	lv_label_set_text(label, "Search");
	lv_obj_center(label);

	lv_style_init(&button_style);
	lv_style_set_bg_color(&button_style, lv_color_white());
	lv_obj_add_style(search_button, &button_style, 0);
}

void main_window::create_file_window()
{
	page_temp = lv_obj_create(screen);
	lv_obj_set_size(page_temp, screen_width*0.92f+10.0f, screen_height*0.75f);
	lv_obj_align_to(page_temp, screen, LV_FLEX_ALIGN_CENTER, 0, screen_height*0.20f);

}

void main_window::create_file_list()
{
	file_list = lv_list_create(screen);

	lv_obj_set_size(file_list, screen_width*0.92f+10.0f, screen_height*0.75f);
	lv_obj_align_to(file_list, screen, LV_FLEX_ALIGN_CENTER, 0, screen_height*0.20f);

	lv_list_add_btn(file_list, LV_SYMBOL_FILE, "image1");
	lv_list_add_btn(file_list, LV_SYMBOL_FILE, "image2");
	lv_list_add_btn(file_list, LV_SYMBOL_FILE, "image3");
	lv_list_add_btn(file_list, LV_SYMBOL_FILE, "image4");
	lv_list_add_btn(file_list, LV_SYMBOL_FILE, "image5");
	lv_list_add_btn(file_list, LV_SYMBOL_FILE, "image6");
	lv_list_add_btn(file_list, LV_SYMBOL_FILE, "image7");
	lv_list_add_btn(file_list, LV_SYMBOL_FILE, "image8");

}


}











