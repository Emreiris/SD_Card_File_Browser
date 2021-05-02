/*
 * audio_speaker_handler.c
 *
 *  Created on: 18 Nis 2021
 *      Author: emrei
 */


#include <stdint.h>
#include "audio_speaker_handler.h"
#include "file_manager.h"
#include "audio_decoder.h"
#include "fatfs.h"
#include "file_manager.h"

const static char audio_file_names[10][30] = {"audio_file_1.wav", "audio_file_2.wav",
		                                      "audio_file_3.wav", "audio_file_4.wav",
											  "audio_file_5.wav", "audio_file_6.wav",
											  "audio_file_7.wav", "audio_file_8.wav",
											  "audio_file_9.wav", "audio_file_10.wav"};


void Audio_File_Out(uint8_t file_number,file_manager_t *file_manage)
{
	static uint8_t wav_descriptor[44];

	uint8_t   buffer_8[128];
	uint16_t  buffer_16[64];

	file_manage->file_result = f_open(&file_manage->file_handler, &audio_file_names[file_number][0], FA_READ);

	file_manage->file_result = f_read(&file_manage->file_handler, wav_descriptor, sizeof(wav_descriptor), (UINT *)file_manage->file_bytes_read);

	if( file_manage->file_result == FR_OK )
	{
		Audio_Characterize(wav_descriptor);
	}



}
