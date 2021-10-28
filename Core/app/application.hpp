/*
 * application.hpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#ifndef APP_APPLICATION_HPP_
#define APP_APPLICATION_HPP_

#include "./windows/main_window.hpp"
#include "displayer_gui_driver.hpp"
#include "touch_screen_gui_driver.hpp"

namespace app
{


class application
{
public:

	application();


	void app_init();
	void app_run();
private:
	 gui::displayer_gui_driver *gui;
	 gui::touch_screen_gui_driver *ts;

};

}

#endif /* APP_APPLICATION_HPP_ */
