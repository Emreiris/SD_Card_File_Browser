/*
 * sdram.cpp
 *
 *  Created on: 28 Nis 2021
 *      Author: emrei
 */

#include <sdram.hpp>
#include "fmc.h"


namespace driver
{

void sdram_handler::init()
{

	FMC_SDRAM_CommandTypeDef   command;
    FMC_SDRAM_TimingTypeDef    SdramTiming = {0};

    hsdram1.Instance = FMC_SDRAM_DEVICE;

    hsdram1.Init.SDBank = FMC_SDRAM_BANK1;
    hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_8;
    hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_12;
    hsdram1.Init.MemoryDataWidth = memory_width;
    hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_2;
    hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_2;
    hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
    hsdram1.Init.SDClockPeriod = clock_period;
    hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_ENABLE;
    hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_0;

    SdramTiming.LoadToActiveDelay = 2;
    SdramTiming.ExitSelfRefreshDelay = 6;
    SdramTiming.SelfRefreshTime = 4;
    SdramTiming.RowCycleDelay = 6;
    SdramTiming.WriteRecoveryTime = 2;
    SdramTiming.RPDelay = 2;
    SdramTiming.RCDDelay = 2;

    HAL_SDRAM_Init(&hsdram1, &SdramTiming);

    this->init_sequence(&hsdram1, &command);

}

void sdram_handler::init_sequence(SDRAM_HandleTypeDef *sdram_handle,
		                          FMC_SDRAM_CommandTypeDef *command)
{
	  volatile uint32_t temp_val;

	  command->CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
	  command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	  command->AutoRefreshNumber = 1;
	  command->ModeRegisterDefinition = 0;

	  HAL_SDRAM_SendCommand(sdram_handle, command, timeout);

	  command->CommandMode = FMC_SDRAM_CMD_PALL;
	  command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	  command->AutoRefreshNumber = 1;
	  command->ModeRegisterDefinition = 0;

	  HAL_SDRAM_SendCommand(sdram_handle, command, timeout);

	  command->CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
	  command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	  command->AutoRefreshNumber = 8;
	  command->ModeRegisterDefinition = 0;

	  HAL_SDRAM_SendCommand(sdram_handle, command, timeout);

	  temp_val = (uint32_t)burst_length|burst_type_seq|cas_latency| \
			  	  	  	   operating_mode_standart|writeburst_mode_single;

	  command->CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
	  command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	  command->AutoRefreshNumber = 1;
	  command->ModeRegisterDefinition = temp_val;

	  HAL_SDRAM_SendCommand(sdram_handle, command, timeout);
	  HAL_SDRAM_SetAutoRefreshNumber(&hsdram1, refresh_time);

}

}

