/*
 * audio_speaker_handler.c
 *
 *  Created on: 18 Nis 2021
 *      Author: emrei
 */

#if 0
#include <stdint.h>
#include "audio_speaker_handler.h"
#include "file_manager.h"
#include "audio_decoder.h"
#include "fatfs.h"
#include "file_manager.h"
#include "dac.h"
#include "tim.h"

static audio_file_info_t audio_file_info;
const static char audio_file_names[10][30] = {"audio_file_1.wav", "audio_file_2.wav",
		                                      "audio_file_3.wav", "audio_file_4.wav",
											  "audio_file_5.wav", "audio_file_6.wav",
											  "audio_file_7.wav", "audio_file_8.wav",
											  "audio_file_9.wav", "audio_file_10.wav"};

static void Timer_Configure(uint32_t frequency);

void Audio_File_Out(uint8_t file_number,file_manager_t *file_manage)
{
	static uint8_t wav_descriptor[44];
	static int32_t remained_data = 0;
	uint8_t   buffer_8[128];
	uint16_t  buffer_16[128];

	file_manage->file_result = f_open(&file_manage->file_handler, &audio_file_names[file_number][0], FA_READ);

	file_manage->file_result = f_read(&file_manage->file_handler, wav_descriptor, sizeof(wav_descriptor), (UINT *)file_manage->file_bytes_read);

	if( file_manage->file_result == FR_OK )
	{
		audio_file_info = Audio_Characterize(wav_descriptor);
	}

	Timer_Configure(audio_file_info.sample_rate);

	if( audio_file_info.bits_per_sample == 8 )
	{
		while( audio_file_info.data_length > remained_data )
		{
			f_read(&file_manage->file_handler, buffer_8, sizeof(buffer_8), (UINT *)file_manage->file_bytes_read);

		}
	}
	else if(audio_file_info.bits_per_sample == 16 )
	{
		while( audio_file_info.data_length > remained_data )
		{

			f_read(&file_manage->file_handler, buffer_16, sizeof(buffer_16), (UINT *)file_manage->file_bytes_read);

			/* TODO: Speaker will be driven via DAC, timer has to be configured. */
		}
	}

}

static void Timer_Configure(uint32_t frequency)
{
	/*
	 * https://en.wikipedia.org/wiki/Sampling_(signal_processing)#Sampling_rate
	 * Timer main clock freq : 24Mhz
	 */
	/*TODO: Re-arrange the numbers.*/
	static const uint32_t freq_table[]         = { 8000,    16000,   22050,  44100,   48000,  88200, 96000};
	static const timer_value_t timer_values[7] = {{99,74}, {49,74},  {2,150},  {2,75},  {49,24}, {2,38}, {24,24} };

	uint8_t index;

	for(uint8_t i = 0; i < 7; i++)
	{
		if(frequency == freq_table[i])
		{
			index = i;
			break;
		}
	}

	HAL_TIM_Base_Stop(&htim8);

    htim8.Init.Prescaler = timer_values[index].prescaler;
	htim8.Init.Period    = timer_values[index].autoreload;

	HAL_TIM_Base_Init(&htim8);

	HAL_TIM_Base_Start(&htim8);

}

#endif
