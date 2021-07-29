/*
 * sdram_const.hpp
 *
 *  Created on: 25 Tem 2021
 *      Author: emrei
 */

#ifndef MODULES_CPP_SDRAM_CPP_SDRAM_CONST_HPP_
#define MODULES_CPP_SDRAM_CPP_SDRAM_CONST_HPP_

#include "fmc.h"

class sdram_const
{
protected:
	static constexpr uint32_t bank_address	 = 0xC0000000;
	static constexpr uint32_t memory_width	 = FMC_SDRAM_MEM_BUS_WIDTH_16;
	static constexpr uint32_t clock_period	 = FMC_SDRAM_CLOCK_PERIOD_2;
	static constexpr uint32_t timeout     	 = 0xFFFF;
	static constexpr uint32_t refresh_time	 = 0x0603;

	static constexpr uint16_t burst_length   = 0x0000;
	static constexpr uint16_t burst_type_seq = 0x0000;
	static constexpr uint16_t cas_latency    = 0x0020;

	static constexpr uint16_t operating_mode_standart    = 0x0000;
	static constexpr uint16_t writeburst_mode_single     = 0x0200;

};




#endif /* MODULES_CPP_SDRAM_CPP_SDRAM_CONST_HPP_ */
