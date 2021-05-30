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
#include "ui_components.hpp"

class application: public event_handler, ui_components
{
public:
	void app_init();
	void app_run();
	void app_get_files();
private:

};



#endif /* APP_APPLICATION_HPP_ */
