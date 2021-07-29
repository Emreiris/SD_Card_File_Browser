/*
 * displayer_gui_driver.h
 *
 *  Created on: 23 May 2021
 *      Author: emrei
 */

#ifndef MODULES_CPP_SCREEN_CPP_DISPLAYER_GUI_DRIVER_HPP_
#define MODULES_CPP_SCREEN_CPP_DISPLAYER_GUI_DRIVER_HPP_

#include "lvgl.h"
#include "displayer.hpp"
#include "sdram.hpp"

namespace gui
{

class displayer_gui_driver
{
public:
	displayer_gui_driver() = default;
	void gui_init();
	static void displayer_interface(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
private:
	static inline driver::displayer display;
	static inline driver::sdram_handler sdram;

};

}

#endif /* MODULES_CPP_SCREEN_CPP_DISPLAYER_GUI_DRIVER_HPP_ */
