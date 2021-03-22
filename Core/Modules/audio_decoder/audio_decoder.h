/*
 * audio_decoder.h
 *
 *  Created on: Mar 20, 2021
 *      Author: emrei
 */

#ifndef MODULES_AUDIO_DECODER_AUDIO_DECODER_H_
#define MODULES_AUDIO_DECODER_AUDIO_DECODER_H_

#include <stdint.h>

 /*
  * resource : http://soundfile.sapp.org/doc/WaveFormat/
  */

typedef struct __audio_file_format
{
	uint8_t chunk_id[4];        /* big endian    */
	uint8_t chunk_size[4];      /* little endian */
	uint8_t format[4];          /* big endian    */
	uint8_t subchunk1_id[4];    /* big endian    */
	uint8_t subchunk1_size[4];  /* little endian */
	uint8_t audio_format[2];    /* little endian */
	uint8_t num_channels[2];    /* little endian */
	uint8_t sample_rate[4];     /* little endian */
	uint8_t byte_rate[4];       /* little endian */
	uint8_t block_align[2];     /* little endian */
	uint8_t bits_per_sample[2]; /* little endian */
	uint8_t subchunk2_id[4];    /* big endian    */
	uint8_t subchunk2_size[4];  /* little endian */
}audio_file_attributes_t;

typedef struct __audio_file_info
{
	uint8_t   channel_number;
	uint16_t  sample_rate;
	uint8_t   bits_per_sample;
} audio_file_info_t;


#endif /* MODULES_AUDIO_DECODER_AUDIO_DECODER_H_ */
