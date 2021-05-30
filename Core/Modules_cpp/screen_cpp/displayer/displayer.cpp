/*
 * displayer.cpp
 *
 *  Created on: 23 May 2021
 *      Author: emrei
 */

#include "displayer.hpp"

#include <stdint.h>
#include <stdlib.h>

/**
  * @brief  Displayer Size
  */
#define  DISPLAYER_WIDTH    ((uint16_t)480)          /* LCD PIXEL WIDTH            */
#define  DISPLAYER_HEIGHT   ((uint16_t)272)          /* LCD PIXEL HEIGHT           */

/**
  * @brief  Displayer Timing
  */

#define  DISPLAYER_HSYNC            ((uint16_t)41)   /* Horizontal synchronization */
#define  DISPLAYER_HBP              ((uint16_t)13)   /* Horizontal back porch      */
#define  DISPLAYER_HFP              ((uint16_t)32)   /* Horizontal front porch     */
#define  DISPLAYER_VSYNC            ((uint16_t)10)   /* Vertical synchronization   */
#define  DISPLAYER_VBP              ((uint16_t)2)    /* Vertical back porch        */
#define  DISPLAYER_VFP              ((uint16_t)2)

#define LCD_BACKLIGHT_STATE(x) \
	HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, x)

/*
 * LCD Displayer enable disable functionality
 */

#define LCD_DISP_STATE(x) \
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_12, x)

#define FB_START_ADDRRESS ((uint32_t)0xC0000000)

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
	LCD_BACKLIGHT_STATE(GPIO_PIN_SET);
	LCD_DISP_STATE(GPIO_PIN_SET);

	lcd_handle.Instance = LTDC;
	lcd_handle.Init.HSPolarity = LTDC_HSPOLARITY_AL;
	lcd_handle.Init.VSPolarity = LTDC_VSPOLARITY_AL;
	lcd_handle.Init.DEPolarity = LTDC_DEPOLARITY_AL;
	lcd_handle.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
	lcd_handle.Init.HorizontalSync = (DISPLAYER_HSYNC - 1);
	lcd_handle.Init.VerticalSync = (DISPLAYER_VSYNC - 1);
	lcd_handle.Init.AccumulatedHBP = (DISPLAYER_HSYNC + DISPLAYER_HBP - 1);
	lcd_handle.Init.AccumulatedVBP = (DISPLAYER_VSYNC + DISPLAYER_VBP - 1);
	lcd_handle.Init.AccumulatedActiveH = (DISPLAYER_HEIGHT + DISPLAYER_VSYNC
			+ DISPLAYER_VBP - 1);
	lcd_handle.Init.AccumulatedActiveW = (DISPLAYER_WIDTH + DISPLAYER_HSYNC
			+ DISPLAYER_HBP - 1);
	lcd_handle.Init.TotalHeigh = (DISPLAYER_HEIGHT + DISPLAYER_VSYNC
			+ DISPLAYER_VBP + DISPLAYER_VFP - 1);
	lcd_handle.Init.TotalWidth = (DISPLAYER_WIDTH + DISPLAYER_HSYNC
			+ DISPLAYER_HBP + DISPLAYER_HFP - 1);
	lcd_handle.Init.Backcolor.Blue = 0;
	lcd_handle.Init.Backcolor.Green = 0;
	lcd_handle.Init.Backcolor.Red = 0;

	HAL_LTDC_Init(&lcd_handle);

	this->config_layer();

}

void displayer::config_layer()
{
	lcd_handle.LayerCfg[0].WindowX0 = 0;
	lcd_handle.LayerCfg[0].WindowX1 = DISPLAYER_WIDTH;
	lcd_handle.LayerCfg[0].WindowY0 = 0;
	lcd_handle.LayerCfg[0].WindowY1 = DISPLAYER_HEIGHT;
	lcd_handle.LayerCfg[0].PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
	lcd_handle.LayerCfg[0].Alpha = 255;
	lcd_handle.LayerCfg[0].Alpha0 = 0;
	lcd_handle.LayerCfg[0].BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;
	lcd_handle.LayerCfg[0].BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;
	lcd_handle.LayerCfg[0].FBStartAdress = (uint32_t)0xC0000000;
	lcd_handle.LayerCfg[0].ImageWidth = DISPLAYER_WIDTH;
	lcd_handle.LayerCfg[0].ImageHeight = DISPLAYER_HEIGHT;
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
