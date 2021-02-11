/*
 * disk_managing_system.c
 *
 *  Created on: 7 Şub 2021
 *      Author: emrei
 */

#include <file_browser.h>
#include <stdint.h>
#include <lvgl.h>

#include "file_manager.h"
#include "displayer_gui_driver.h"
#include "touch_screen_gui_driver.h"


extern char file_names[4][32];


void FB_Init(void)
{
	  Displayer_GUI_Init();
	  Touch_Screen_Init();
}


void FB_Main_Screen(void)
{

	static lv_obj_t *main_screen;

	lv_obj_t *list = lv_list_create(main_screen, NULL);
	if((File_Init() == FR_OK))
	{

	}

	main_screen = lv_scr_act();

	lv_obj_t *list_btn;

	for(size_t i = 0; i < 4; i++)
	{
	list_btn = lv_list_add_btn(list, LV_SYMBOL_FILE,&file_names[i][0]);
	}

	lv_scr_load(main_screen);

}
