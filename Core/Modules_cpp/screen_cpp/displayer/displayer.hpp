/*
 * displayer.hpp
 *
 *  Created on: 23 May 2021
 *      Author: emrei
 */

#ifndef MODULES_CPP_SCREEN_CPP_DISPLAYER_HPP_
#define MODULES_CPP_SCREEN_CPP_DISPLAYER_HPP_
#include <stdint.h>
#include "stm32f7xx.h"

class displayer
{
public:
	displayer();
	void init();
	void draw_pixel(int16_t x_pos, int16_t y_pos, uint16_t color);
	void config_layer();
private:
	LTDC_HandleTypeDef lcd_handle;

};


#endif /* MODULES_CPP_SCREEN_CPP_DISPLAYER_HPP_ */
