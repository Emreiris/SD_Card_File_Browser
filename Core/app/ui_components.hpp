/*
 * ui_components.hpp
 *
 *  Created on: 30 May 2021
 *      Author: emrei
 */

#ifndef APP_UI_COMPONENTS_HPP_
#define APP_UI_COMPONENTS_HPP_

#include "lvgl.h"

class ui_components
{
public:
	void file_list_create();
	void file_list_search();

	void search_bar_create();
	void search_bar_open();

	void keyboard_create();
	void keyboard_handle();
protected:
	lv_obj_t* main_screen;
	lv_obj_t* get_screen();
    void set_screen(lv_obj_t* screen);
	lv_obj_t* file_list;
	lv_obj_t* file_search_ta;
};



#endif /* APP_UI_COMPONENTS_HPP_ */
