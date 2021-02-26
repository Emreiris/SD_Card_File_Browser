/*
 * keyboard_manager.c
 *
 *  Created on: 23 Şub 2021
 *      Author: emrei
 */
#include <lvgl.h>
#include <keyboard_manager.h>


void Keyboard_Create(keyboard_handle_t *keyboard_handle, lv_obj_t *parent)
{
	keyboard_handle->keyboard = lv_keyboard_create(parent, NULL);
	lv_obj_set_size(keyboard_handle->keyboard, LV_HOR_RES_MAX, LV_VER_RES_MAX/2);
}

void Keyboard_Destroy(keyboard_handle_t *keyboard_handle)
{
	lv_obj_del(keyboard_handle->keyboard);
}

