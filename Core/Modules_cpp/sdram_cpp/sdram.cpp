/*
 * sdram.cpp
 *
 *  Created on: 28 Nis 2021
 *      Author: emrei
 */

#include "sdram.hpp"
#include "fmc.h"

void sdram_handler::init()
{
	sdram_handle.Instance = FMC_SDRAM_DEVICE;

	sdram_handle.Init.SDBank = FMC_SDRAM_BANK1;
	sdram_handle.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_8;
	sdram_handle.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_12;
	sdram_handle.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_16;
	sdram_handle.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_2;
	sdram_handle.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_2;
	sdram_handle.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
	sdram_handle.Init.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_2;
	sdram_handle.Init.ReadBurst = FMC_SDRAM_RBURST_ENABLE;
	sdram_handle.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_0;
}

void sdram_handler::init_sequence()
{
	  volatile uint32_t temp_val;

	  command->CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
	  command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	  command->AutoRefreshNumber = 1;
	  command->ModeRegisterDefinition = 0;

	  HAL_SDRAM_SendCommand(&sdram_handle, command, SDRAM_TIMEOUT);

	  HAL_Delay(1);

	  command->CommandMode = FMC_SDRAM_CMD_PALL;
	  command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	  command->AutoRefreshNumber = 1;
	  command->ModeRegisterDefinition = 0;

	  HAL_SDRAM_SendCommand(&sdram_handle, command, SDRAM_TIMEOUT);

	  command->CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
	  command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	  command->AutoRefreshNumber = 8;
	  command->ModeRegisterDefinition = 0;

	  HAL_SDRAM_SendCommand(&sdram_handle, command, SDRAM_TIMEOUT);

	  temp_val = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_1          |
	                       SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
	                       SDRAM_MODEREG_CAS_LATENCY_2           |
	                       SDRAM_MODEREG_OPERATING_MODE_STANDARD |
	                       SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

	  command->CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
	  command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	  command->AutoRefreshNumber = 1;
	  command->ModeRegisterDefinition = temp_val;

	  HAL_SDRAM_SendCommand(&sdram_handle, command, SDRAM_TIMEOUT);
	  HAL_SDRAM_SetAutoRefreshNumber(&hsdram1, SDRAM_REFRESH_TIME);
}


