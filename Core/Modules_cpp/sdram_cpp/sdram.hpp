/*
 * sdram.hpp
 *
 *  Created on: 28 Nis 2021
 *      Author: emrei
 */

#ifndef MODULES_CPP_SDRAM_CPP_SDRAM_H_
#define MODULES_CPP_SDRAM_CPP_SDRAM_H_

#include "fmc.h"

#define SDRAM_BANK_ADDR                  ((uint32_t)0xC0000000)
#define SDRAM_MEMORY_WIDTH               FMC_SDRAM_MEM_BUS_WIDTH_16
#define SDCLOCK_PERIOD                   FMC_SDRAM_CLOCK_PERIOD_2
#define SDRAM_TIMEOUT                    ((uint32_t)0xFFFF)
#define SDRAM_REFRESH_TIME               ((uint32_t)0x0603)


#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)

class sdram_handler
{

public:
	sdram_handler()
	{
	}

	void init();
	void init_sequence();
private:
	SDRAM_HandleTypeDef sdram_handle;
	FMC_SDRAM_CommandTypeDef *command;
	static int entity_counter;
};



#endif /* MODULES_CPP_SDRAM_CPP_SDRAM_H_ */
