#pragma once
#include <stdint.h>

#define BYTES_PER_FRAME 8
#define SAMPLES_PER_FRAME 14
#define NIBBLES_PER_FRAME 16

typedef struct
{
	int16_t coef[16];
	uint16_t gain;
	uint16_t pred_scale;
	int16_t yn1;
	int16_t yn2;

	uint16_t loop_pred_scale;
	int16_t loop_yn1;
	int16_t loop_yn2;

} ADPCMINFO;