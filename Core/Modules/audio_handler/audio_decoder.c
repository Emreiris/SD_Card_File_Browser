/*
 * audio_decoder.c
 *
 *  Created on: Mar 20, 2021
 *      Author: emrei
 */

#if 0
#include "audio_decoder.h"

#include <stdint.h>
#include <string.h>


/*
 * param   : wav file descriptor 44 bytes.
 * retval  : File description structure.
 * brief   : This function extracts the character of wav file.
 */

audio_file_info_t Audio_Characterize(uint8_t descriptor[static 44])
{
	audio_file_info_t audio_info = {0};

	uint32_t temp_32;
	uint16_t temp_16;

	if( !strncmp((char *)&descriptor[0], "RIFF", 4) )
	{
		audio_info.audio_state = AUDIO_OK;
	}

	memcpy(&temp_32, &descriptor[4], 4);

	audio_info.data_length = temp_32 - 36;

	if( !strncmp((char *)&descriptor[8], "WAVE", 4) )
	{
		audio_info.audio_state = AUDIO_OK;
	}

	if( !strncmp((char *)&descriptor[12], "fmt ", 4) )
	{
		audio_info.audio_state = AUDIO_OK;
	}

	memcpy(&temp_32, &descriptor[16], 4);

	if(temp_32 == 16)
	{
		audio_info.audio_state = AUDIO_OK;
	}

	memcpy(&temp_16, &descriptor[20], 2);

	if(temp_32 == 1)
	{
		audio_info.audio_state = AUDIO_OK;
	}

	memcpy(&temp_16, &descriptor[22], 2);

	audio_info.channel_number = temp_16;

	memcpy(&temp_32, &descriptor[24], 4);

	audio_info.sample_rate = temp_32;

	memcpy(&temp_16, &descriptor[34], 2);

	audio_info.bits_per_sample = temp_16;

	return audio_info;
}

#endif
