/*
 * keyboard_manager.h
 *
 *  Created on: 23 Şub 2021
 *      Author: emrei
 */

#ifndef APPLICATION_SUBMODULES_KEYBOARD_MANAGER_H_
#define APPLICATION_SUBMODULES_KEYBOARD_MANAGER_H_

#include <lvgl.h>

typedef struct _keyboard_handle_t
{
	lv_obj_t *keyboard;
}keyboard_handle_t;

void Keyboard_Create(keyboard_handle_t *keyboard_handle, lv_obj_t *parent, lv_obj_t *text_area);
void Keyboard_Destroy(keyboard_handle_t *keyboard_handle);

#endif /* APPLICATION_SUBMODULES_KEYBOARD_MANAGER_H_ */
