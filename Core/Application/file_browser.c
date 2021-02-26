/*
 * disk_managing_system.c
 *
 *  Created on: 7 Şub 2021
 *      Author: emrei
 */

#include <stdint.h>

#include "file_browser.h"
#include "lvgl.h"
#include "stm32f7xx_hal.h"
#include "file_manager.h"
#include "displayer_gui_driver.h"
#include "touch_screen_gui_driver.h"

#define DISK_DETECT() \
	BSP_SD_IsDetected()

typedef struct __fb_file_search
{
	lv_obj_t *file_list;
	lv_obj_t *file_text_area;
} fb_file_search_t;

lv_obj_t *main_screen;

static file_manager_t file_manage = {.file_result = FR_DISK_ERR, .file_counter = 0};
static fb_file_search_t file_search;

static void FB_Message_Warning(lv_obj_t *parent, uint16_t x_pos, uint16_t y_pos, const char *message);
static void FB_File_Scan(fb_file_search_t *file_search, file_manager_t *file_manage);

static void FB_Search_Browser(fb_file_search_t *file_search, file_manager_t *file_manage);
static void FB_Search_Browser_Callback(lv_obj_t *obj, lv_event_t event);

/* Will be tested */


void FB_Init(void)
{
	  Displayer_GUI_Init();
	  Touch_Screen_Init();
	  File_Init(&file_manage);
}

/* Will be tested */

void FB_Main_Screen(void)
{

	main_screen = lv_scr_act();

	file_search.file_list = lv_list_create(main_screen, NULL);
	lv_obj_set_pos(file_search.file_list, 0, 30);
	lv_obj_set_size(file_search.file_list,LV_HOR_RES_MAX , LV_VER_RES_MAX-30 );

	file_search.file_text_area = lv_textarea_create(main_screen, NULL);
	lv_obj_set_pos(file_search.file_text_area, 0, 0);
	lv_obj_set_size(file_search.file_text_area,LV_HOR_RES_MAX , 30);


	FB_File_Scan(&file_search, &file_manage);
	lv_scr_load(main_screen);
	FB_Search_Browser(&file_search, &file_manage);

}


/* Tested, working correctly */

static void FB_Message_Warning(lv_obj_t *parent, uint16_t x_pos, uint16_t y_pos, const char *message)
{

	static const char *btn_str[7] = {"Retry", "Close", ""};

	lv_obj_t *message_box = lv_msgbox_create(parent, NULL);
	lv_obj_set_pos(message_box, x_pos, y_pos);
	lv_obj_set_size(message_box, 200, 200);

	lv_msgbox_set_text(message_box, message);
	lv_msgbox_add_btns(message_box, btn_str);
	lv_msgbox_stop_auto_close(message_box);

}

static void FB_File_Scan(fb_file_search_t *file_search, file_manager_t *file_manage)
{

	File_Change_Dir(file_manage, "my_folder_1");

	lv_textarea_set_text(file_search->file_text_area, file_manage->file_current_dir);

	for(int8_t i = 0; i < 3; ++i)
	{
		do   /* At least one time search is a must. */
		{
			File_Find_File(file_manage, i);

			if( file_manage->file_counter != 0)
			{
				lv_list_add_btn(file_search->file_list, LV_SYMBOL_FILE, file_manage->file_info.fname);
			}
		} while( file_manage->file_counter > 0 );

	}

}

static void FB_Search_Browser(fb_file_search_t *file_search, file_manager_t *file_manage)
{

	lv_obj_set_event_cb(file_search->file_text_area, FB_Search_Browser_Callback);

}

static void FB_Search_Browser_Callback(lv_obj_t *obj, lv_event_t event)
{

	if( event == LV_EVENT_CLICKED )
	{

	}
}
