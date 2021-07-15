/*
 * application.hpp
 *
 *  Created on: 25 May 2021
 *      Author: emrei
 */

#ifndef APP_APPLICATION_HPP_
#define APP_APPLICATION_HPP_

#include "./windows/main_window.hpp"

class application
{
public:
	void app_init();
	void app_run();
private:

	main_window mw;

};



#endif /* APP_APPLICATION_HPP_ */
