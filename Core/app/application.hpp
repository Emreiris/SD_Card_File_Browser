/*
 * application.hpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#ifndef APP_APPLICATION_HPP_
#define APP_APPLICATION_HPP_

#include "event_handler.hpp"
#include "lvgl.h"

class application: public event_handler
{
public:
	void app_init();
	void app_run();
	void app_get_files();
private:
	lv_obj_t* file_list;
	lv_obj_t* file_search_ta;
};



#endif /* APP_APPLICATION_HPP_ */
