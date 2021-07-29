/*
 * touch_screen_gui_driver.hpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#ifndef MODULES_CPP_SCREEN_CPP_TOUCH_SCREEN_TOUCH_SCREEN_GUI_DRIVER_HPP_
#define MODULES_CPP_SCREEN_CPP_TOUCH_SCREEN_TOUCH_SCREEN_GUI_DRIVER_HPP_


#include "lvgl.h"
#include "touch_screen.hpp"
#include <functional>

namespace gui
{

class touch_screen_gui_driver
{
public:
	void ts_init();
	static void ts_interface(struct _lv_indev_drv_t * indev, lv_indev_data_t * data);
	static inline driver::touch_screen ts;
};


}


#endif /* MODULES_CPP_SCREEN_CPP_TOUCH_SCREEN_TOUCH_SCREEN_GUI_DRIVER_HPP_ */
