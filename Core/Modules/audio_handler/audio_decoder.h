/*
 * audio_decoder.h
 *
 *  Created on: Mar 20, 2021
 *      Author: emrei
 */

#ifndef MODULES_AUDIO_HANDLER_AUDIO_DECODER_H_
#define MODULES_AUDIO_HANDLER_AUDIO_DECODER_H_

#if 0
#include <stdint.h>

#define BIG_TO_LITTLE(__num__, __swapped__)               \
	                 (__swapped__ = ((__num__>>24)&0xff) | \
                     ((__num__<<8)  & 0xff0000)          |  \
                     ((__num__>>8)  & 0xff00)            |   \
                     ((__num__<<24) & 0xff000000))

 /*
  * resource : http://soundfile.sapp.org/doc/WaveFormat/
  */

typedef struct __audio_file_info
{
	uint8_t   channel_number;
	uint32_t  sample_rate;
	uint16_t   bits_per_sample;
	uint32_t  data_length;
	enum
	{
		AUDIO_ERROR = 0,
		AUDIO_OK
	}audio_state;
} audio_file_info_t;

audio_file_info_t Audio_Characterize(uint8_t descriptor[static 44]);

#endif

#endif /* MODULES_AUDIO_HANDLER_AUDIO_DECODER_H_ */
