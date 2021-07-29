/*
 * touch_screen_reglist.hpp
 *
 *  Created on: 29 Tem 2021
 *      Author: emrei
 */

#ifndef MODULES_CPP_SCREEN_CPP_TOUCH_SCREEN_TOUCH_SCREEN_REGLIST_HPP_
#define MODULES_CPP_SCREEN_CPP_TOUCH_SCREEN_TOUCH_SCREEN_REGLIST_HPP_

class touch_screen_reglist
{
protected:
	static constexpr uint8_t address_read = 0x71;

	static constexpr uint8_t touch_num    = 0x02;
	static constexpr uint8_t touch_x_h    = 0x03;
	static constexpr uint8_t touch_x_l    = 0x04;
	static constexpr uint8_t touch_y_h    = 0x05;
	static constexpr uint8_t touch_y_l    = 0x06;
};




#endif /* MODULES_CPP_SCREEN_CPP_TOUCH_SCREEN_TOUCH_SCREEN_REGLIST_HPP_ */
