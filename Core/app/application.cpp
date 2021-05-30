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


void application::app_init()
{
	gui.gui_init();
	ts.ts_init();

	file_search_ta = lv_textarea_create(lv_scr_act());
	lv_obj_set_pos(file_search_ta, 5, 5);
	lv_obj_set_size(file_search_ta, lv_pct(95), lv_pct(15));

}

void application::app_run()
{


}


