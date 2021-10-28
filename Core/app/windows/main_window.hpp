/*
 * main_window.hpp
 *
 *  Created on: 14 Haz 2021
 *      Author: emrei
 */

#ifndef APP_WINDOWS_MAIN_WINDOW_HPP_
#define APP_WINDOWS_MAIN_WINDOW_HPP_

#include <map>
#include <string>
#include "lvgl.h"

namespace gui
{

class main_window
{
public:
	main_window();

	static main_window& get_instance()
	{
		static main_window instance;

		return instance;
	}

	void create_text_input();
	void create_search_button();
	void create_file_window();
	void create_keyboard();
	void create_file_list();
	lv_obj_t* get_screen(){ return screen;}

private:
	lv_coord_t screen_width{0};
	lv_coord_t screen_height{0};

	lv_obj_t* screen{nullptr};
	lv_obj_t* text_input{nullptr};
	lv_obj_t* search_button{nullptr};
	lv_obj_t* page_temp{nullptr};
	lv_obj_t* file_list{nullptr};
	lv_obj_t* keyboard{nullptr};
};

}




#endif /* APP_WINDOWS_MAIN_WINDOW_HPP_ */
