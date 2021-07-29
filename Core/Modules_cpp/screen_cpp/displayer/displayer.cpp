/*
 * displayer.cpp
 *
 *  Created on: 23 May 2021
 *      Author: emrei
 */

#include "displayer.hpp"

#include <stdint.h>
#include <stdlib.h>

namespace driver
{

displayer::displayer()
{
	; /*TODO : It may be filled later.*/
}

/*
 * @param  = none.
 * @retval = none.
 * @brief  = This constructor initialises first layer.
 */


void displayer::init()
{

	lcd_backlight_state(GPIO_PIN_SET);
	lcd_display_state(GPIO_PIN_SET);

	lcd_handle.Instance = LTDC;
	lcd_handle.Init.HSPolarity = LTDC_HSPOLARITY_AL;
	lcd_handle.Init.VSPolarity = LTDC_VSPOLARITY_AL;
	lcd_handle.Init.DEPolarity = LTDC_DEPOLARITY_AL;
	lcd_handle.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
	lcd_handle.Init.HorizontalSync = (displayer_hsync - 1);
	lcd_handle.Init.VerticalSync = (displayer_vsync - 1);
	lcd_handle.Init.AccumulatedHBP = (displayer_hsync + displayer_hbp - 1);
	lcd_handle.Init.AccumulatedVBP = (displayer_vsync + displayer_vbp - 1);
	lcd_handle.Init.AccumulatedActiveH = (displayer_height + displayer_vsync
			+ displayer_vbp - 1);
	lcd_handle.Init.AccumulatedActiveW = (displayer_width + displayer_hsync
			+ displayer_hbp - 1);
	lcd_handle.Init.TotalHeigh = (displayer_height + displayer_vsync
			+ displayer_vbp + displayer_vfp - 1);
	lcd_handle.Init.TotalWidth = (displayer_width + displayer_hsync
			+ displayer_hbp + displayer_hfp - 1);
	lcd_handle.Init.Backcolor.Blue = 0;
	lcd_handle.Init.Backcolor.Green = 0;
	lcd_handle.Init.Backcolor.Red = 0;

	HAL_LTDC_Init(&lcd_handle);

	this->config_layer();

}

void displayer::config_layer()
{
	lcd_handle.LayerCfg[0].WindowX0 = 0;
	lcd_handle.LayerCfg[0].WindowX1 = displayer_width;
	lcd_handle.LayerCfg[0].WindowY0 = 0;
	lcd_handle.LayerCfg[0].WindowY1 = displayer_height;
	lcd_handle.LayerCfg[0].PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
	lcd_handle.LayerCfg[0].Alpha = 255;
	lcd_handle.LayerCfg[0].Alpha0 = 0;
	lcd_handle.LayerCfg[0].BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;
	lcd_handle.LayerCfg[0].BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;
	lcd_handle.LayerCfg[0].FBStartAdress = (uint32_t)fb_start_address;
	lcd_handle.LayerCfg[0].ImageWidth = displayer_width;
	lcd_handle.LayerCfg[0].ImageHeight = displayer_height;
	lcd_handle.LayerCfg[0].Backcolor.Blue = 0;
	lcd_handle.LayerCfg[0].Backcolor.Green = 0;
	lcd_handle.LayerCfg[0].Backcolor.Red = 0;
    HAL_LTDC_ConfigLayer(&lcd_handle, &lcd_handle.LayerCfg[0], 1);
	HAL_LTDC_EnableDither(&lcd_handle);
}

void displayer::draw_pixel(int16_t x_pos, int16_t y_pos, uint16_t color)
{
	*(volatile uint16_t *)(lcd_handle.LayerCfg[0].FBStartAdress+( 2 * (y_pos * lcd_handle.LayerCfg [0] .ImageWidth + x_pos))) = color;
}

}
