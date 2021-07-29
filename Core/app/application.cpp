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
#include <list>
#include <string>

namespace app
{



void application::app_init()
{
	gui.gui_init();

	ts.ts_init();

	lv_obj_t* button = lv_btn_create(lv_scr_act());

	lv_obj_set_pos(button, 10, 10);
	lv_obj_set_size(button, 100, 40);


}

void application::app_run()
{



}

}

