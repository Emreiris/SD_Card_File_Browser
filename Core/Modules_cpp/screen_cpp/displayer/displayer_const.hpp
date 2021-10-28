/*
 * displayer_const.hpp
 *
 *  Created on: Jul 18, 2021
 *      Author: emrei
 */

#ifndef MODULES_CPP_SCREEN_CPP_DISPLAYER_DISPLAYER_CONST_HPP_
#define MODULES_CPP_SCREEN_CPP_DISPLAYER_DISPLAYER_CONST_HPP_

namespace driver
{

class displayer_const
{
protected:
	static constexpr uint16_t displayer_hsync   = 41;  /* Horizontal synchronization */
	static constexpr uint16_t displayer_hbp     = 13;  /* Horizontal back porch      */
	static constexpr uint16_t displayer_hfp     = 32;  /* Horizontal front porch     */
	static constexpr uint16_t displayer_vsync   = 10;  /* Vertical synchronization   */
	static constexpr uint16_t displayer_vbp     = 2;   /* Vertical back porch        */
	static constexpr uint16_t displayer_vfp     = 2;   /* Vertical front porch       */

	static constexpr uint32_t fb_start_address  = 0xC0000000; /* frame buffer address */
};

}

#endif /* MODULES_CPP_SCREEN_CPP_DISPLAYER_DISPLAYER_CONST_HPP_ */
