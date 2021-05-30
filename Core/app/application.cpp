/*
 * application.cpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#include "application.hpp"
#include "displayer_gui_driver.hpp"
#include "touch_screen_gui_driver.hpp"
#include "lvgl.h"

static displayer_gui_driver gui;
static touch_screen_gui_driver ts;

#define test_screen lv_scr_act()

void application::app_init()
{
	gui.gui_init();
	ts.ts_init();

	search_bar_create();
	file_list_create();


}

void application::app_run()
{


}


