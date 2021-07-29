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
#include "displayer_const.hpp"

namespace driver
{


class displayer: public displayer_const
{
public:
	displayer();
	void init();
	void draw_pixel(int16_t x_pos, int16_t y_pos, uint16_t color);
	void config_layer();

	static constexpr uint16_t displayer_width   = 480; /* LCD PIXEL WIDTH            */
	static constexpr uint16_t displayer_height  = 272; /* LCD PIXEL HEIGHT           */

private:
	LTDC_HandleTypeDef lcd_handle;

	static auto inline lcd_backlight_state = [](GPIO_PinState pin_state){ HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, pin_state); };
	static auto inline lcd_display_state   = [](GPIO_PinState pin_state){ HAL_GPIO_WritePin(GPIOI, GPIO_PIN_12, pin_state); };

};

}

#endif /* MODULES_CPP_SCREEN_CPP_DISPLAYER_HPP_ */
