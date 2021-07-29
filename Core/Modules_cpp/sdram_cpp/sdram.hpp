/*
 * sdram.hpp
 *
 *  Created on: 28 Nis 2021
 *      Author: emrei
 */

#ifndef MODULES_CPP_SDRAM_CPP_SDRAM_H_
#define MODULES_CPP_SDRAM_CPP_SDRAM_H_

#include "fmc.h"
#include "sdram_const.hpp"

namespace driver
{

class sdram_handler: public sdram_const
{

public:
	sdram_handler() = default;


	void init();
	void init_sequence(SDRAM_HandleTypeDef *sdram_handle, FMC_SDRAM_CommandTypeDef *command);
private:
	SDRAM_HandleTypeDef hsdram1;
	FMC_SDRAM_CommandTypeDef *command;
};

}

#endif /* MODULES_CPP_SDRAM_CPP_SDRAM_H_ */
