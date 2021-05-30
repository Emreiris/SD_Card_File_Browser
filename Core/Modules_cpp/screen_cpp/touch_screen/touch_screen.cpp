/*
 * touch_screen.cpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#include "touch_screen.hpp"
#include "i2c.h"

/* device register list */

#define DEV_ADDRESS_READ    ((uint8_t)0x71)
#define DEV_ADDRESS_WRITE   ((uint8_t)0x70)

#define DEV_TOUCH_NUM       ((uint8_t)0x02)
#define DEV_TOUCH_X_H       ((uint8_t)0x03)
#define DEV_TOUCH_X_L       ((uint8_t)0x04)
#define DEV_TOUCH_Y_H       ((uint8_t)0x05)
#define DEV_TOUCH_Y_L       ((uint8_t)0x06)

/*
 * definitions
 */

#define I2C_Handle (&hi2c3)  /* XXX:touch screen driver port is connected to I2C3*/

bool touch_screen::is_pressed()
{
	static uint8_t touch_num;

	HAL_I2C_Mem_Read(I2C_Handle, DEV_ADDRESS_READ , DEV_TOUCH_NUM, I2C_MEMADD_SIZE_8BIT, &touch_num, 1, 10);

	if(touch_num > 0)
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

	HAL_I2C_Mem_Read(I2C_Handle, DEV_ADDRESS_READ , DEV_TOUCH_X_H, I2C_MEMADD_SIZE_8BIT, &ts_x[0], 1, 10);
	HAL_I2C_Mem_Read(I2C_Handle, DEV_ADDRESS_READ , DEV_TOUCH_X_L, I2C_MEMADD_SIZE_8BIT, &ts_x[1], 1, 10);

	HAL_I2C_Mem_Read(I2C_Handle, DEV_ADDRESS_READ , DEV_TOUCH_Y_H, I2C_MEMADD_SIZE_8BIT, &ts_y[0], 1, 10);
	HAL_I2C_Mem_Read(I2C_Handle, DEV_ADDRESS_READ , DEV_TOUCH_Y_L, I2C_MEMADD_SIZE_8BIT, &ts_y[1], 1, 10);

	*touch_x = ts_x[1] + ((ts_x[0] & 0x0F) << 8);
	*touch_y = ts_y[1] + ((ts_y[0] & 0x0F) << 8);
}

