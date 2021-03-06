/*
 * application.cpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#include "application.hpp"
#include "displayer_gui_driver.hpp"
#include "touch_screen_gui_driver.hpp"
#include "file_manager.hpp"
#include "./windows/main_window.hpp"

#include "lvgl.h"
#include <list>
#include <string>

static displayer_gui_driver gui;
static touch_screen_gui_driver ts;
file_manager fm;

/* Add file extention to list */



void application::app_init()
{
	main_window mw;

	gui.gui_init();
	ts.ts_init();
	fm.file_manager_init();

	mw.create_window();

	mw.refresh_file_list();
}

void application::app_run()
{



}


