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


#include "lvgl.h"
#include <string>
#include "windows/main_window.hpp"


namespace app
{

application::application():gui(new gui::displayer_gui_driver()), ts(new gui::touch_screen_gui_driver())
{

}

void application::app_init()
{
	gui->gui_init();
	ts->ts_init();

	lv_scr_load(gui::main_window::get_instance().get_screen());

}

void application::app_run()
{



}

}

