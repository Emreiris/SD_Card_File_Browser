/*
 * displayer_gui_driver.cpp
 *
 *  Created on: 23 May 2021
 *      Author: emrei
 */

#include "displayer_gui_driver.hpp"
#include "lvgl.h"

#define DISPLAY_HOR (480)
#define DISPLAY_VER (272)

static displayer display;

void displayer_gui_driver::gui_init()
{
	static sdram_handler sdram;

	sdram.init();
	display.init();

	lv_init();

	static lv_disp_draw_buf_t disp_buf;
	static lv_disp_drv_t disp_drv;
	static lv_color_t buf_1[DISPLAY_HOR * 10];

	lv_disp_draw_buf_init(&disp_buf, buf_1, NULL, DISPLAY_HOR*10);

	lv_disp_drv_init(&disp_drv);

	disp_drv.draw_buf = &disp_buf;
	disp_drv.hor_res = DISPLAY_HOR;
	disp_drv.ver_res = DISPLAY_VER;
	disp_drv.flush_cb = this->displayer_interface;

	lv_disp_drv_register(&disp_drv);

	lv_disp_flush_ready(&disp_drv);

}

void displayer_gui_driver::displayer_interface(lv_disp_drv_t *disp,const lv_area_t* area,lv_color_t* color_p)
{
    static int32_t x, y;

    for(y = area->y1; y <= area->y2; y++)
    {
        for(x = area->x1; x <= area->x2; x++)
        {
        	display.draw_pixel(x, y, (uint32_t)color_p->full);
            color_p++;
        }
    }

    lv_disp_flush_ready(disp);
}

