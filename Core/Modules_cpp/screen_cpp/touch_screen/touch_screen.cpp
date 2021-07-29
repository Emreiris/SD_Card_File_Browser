/*
 * touch_screen.cpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#include "touch_screen.hpp"
#include "i2c.h"



/*
 * definitions
 */

namespace driver
{

#define I2C_Handle (&hi2c3)  /* XXX:touch screen driver port is connected to I2C3*/

bool touch_screen::is_pressed()
{
	uint8_t temp_touch_number;

	HAL_I2C_Mem_Read(I2C_Handle, address_read , touch_num, I2C_MEMADD_SIZE_8BIT, &temp_touch_number, 1, 10);

	if(temp_touch_number > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void touch_screen::read_touch_screen(uint16_t* touch_x, uint16_t* touch_y)
{
	uint8_t ts_x[2];
	uint8_t ts_y[2];

	HAL_I2C_Mem_Read(I2C_Handle, address_read , touch_x_h, I2C_MEMADD_SIZE_8BIT, &ts_x[0], 1, 10);
	HAL_I2C_Mem_Read(I2C_Handle, address_read , touch_x_l, I2C_MEMADD_SIZE_8BIT, &ts_x[1], 1, 10);

	HAL_I2C_Mem_Read(I2C_Handle, address_read , touch_y_h, I2C_MEMADD_SIZE_8BIT, &ts_y[0], 1, 10);
	HAL_I2C_Mem_Read(I2C_Handle, address_read , touch_y_l, I2C_MEMADD_SIZE_8BIT, &ts_y[1], 1, 10);

	*touch_x = ts_x[1] + ((ts_x[0] & 0x0F) << 8);
	*touch_y = ts_y[1] + ((ts_y[0] & 0x0F) << 8);
}

}
