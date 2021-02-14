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

#define DISK_DETECT() \
	BSP_SD_IsDetected()

file_manager_t file_manage = {.file_result = FR_DISK_ERR};

static void FB_Message_Warning(lv_obj_t *parent, uint16_t x_pos, uint16_t y_pos, const char *message);

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

}


/* Will be tested */

static void FB_Message_Warning(lv_obj_t *parent, uint16_t x_pos, uint16_t y_pos, const char *message)
{
	const char * btn_str[] = {"Retry", "Close"};
	lv_obj_t *message_box = lv_msgbox_create(parent, NULL);

	lv_obj_set_pos(message_box, x_pos, y_pos);

	lv_msgbox_set_text(message_box, message);
	lv_msgbox_add_btns(message_box, btn_str);

}

