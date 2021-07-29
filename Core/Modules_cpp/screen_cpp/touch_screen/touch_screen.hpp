/*
 * touch_screen.hpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#ifndef MODULES_CPP_SCREEN_CPP_TOUCH_SCREEN_TOUCH_SCREEN_HPP_
#define MODULES_CPP_SCREEN_CPP_TOUCH_SCREEN_TOUCH_SCREEN_HPP_

#include <stdint.h>
#include "touch_screen_reglist.hpp"

namespace driver
{
class touch_screen: public touch_screen_reglist
{
public:
	bool is_pressed();
	void read_touch_screen(uint16_t *touch_x, uint16_t *touch_y);

};

}

#endif /* MODULES_CPP_SCREEN_CPP_TOUCH_SCREEN_TOUCH_SCREEN_HPP_ */
