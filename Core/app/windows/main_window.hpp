/*
 * main_window.hpp
 *
 *  Created on: 14 Haz 2021
 *      Author: emrei
 */

#ifndef APP_WINDOWS_MAIN_WINDOW_HPP_
#define APP_WINDOWS_MAIN_WINDOW_HPP_

#include "lvgl.h"

enum class main_window_states
{
	START = 1,
	LIST_FILES,
	SEARCH_FILES,
	OPEN_FOLDER,
	OPEN_FILE,
	ERROR_OCCURED,
	IDLE
};

class main_window
{
public:
	main_window();

	void create_window();
	main_window_states current_state = main_window_states::START;

private:
	/* main_window widgets created, only needs to be */
	void search_file_create();
	void file_list_create();
	lv_obj_t* get_screen() { return lv_scr_act();}

	/* runtime event creators */
	lv_obj_t* main_screen;
	lv_obj_t* file_search;
	lv_obj_t* file_list;
	lv_obj_t* list_button;


};




#endif /* APP_WINDOWS_MAIN_WINDOW_HPP_ */
