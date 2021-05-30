/*
 * touch_screen_gui_driver.cpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#include "touch_screen_gui_driver.hpp"
#include "lvgl.h"
#include "i2c.h"

void touch_screen_gui_driver::ts_init()
{

	MX_I2C3_Init();

	static lv_indev_drv_t indev_drv;
	lv_indev_drv_init(&indev_drv);
	indev_drv.type = LV_INDEV_TYPE_POINTER;
	indev_drv.read_cb = this->ts_interface;
	lv_indev_drv_register(&indev_drv);
}

void touch_screen_gui_driver::ts_interface(struct _lv_indev_drv_t * indev, lv_indev_data_t * data)
{
	static touch_screen ts;
	uint16_t ts_x;
	uint16_t ts_y;

	data->state =  ts.is_pressed() ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;

	if (data->state == LV_INDEV_STATE_PR)
	{
		ts.read_touch_screen(&ts_x, &ts_y);
	}

	data->point.x = (int16_t)ts_y;
	data->point.y = (int16_t)ts_x;

}


