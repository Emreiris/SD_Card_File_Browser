/*
 * main_window.hpp
 *
 *  Created on: 14 Haz 2021
 *      Author: emrei
 */

#ifndef APP_WINDOWS_MAIN_WINDOW_HPP_
#define APP_WINDOWS_MAIN_WINDOW_HPP_

#include "lvgl.h"


void button_event_handler(lv_event_t * e);

class main_window
{
public:
	main_window();

	void create_window();

	void refresh_file_list();

private:

	friend void button_event_handler(lv_event_t * e);
	void search_file_create();
	void file_list_create();
	lv_obj_t* get_screen() { return lv_scr_act();}

	lv_obj_t* main_screen;
	lv_obj_t* file_search;
	lv_obj_t* file_list;
	lv_obj_t* list_button;

};




#endif /* APP_WINDOWS_MAIN_WINDOW_HPP_ */
