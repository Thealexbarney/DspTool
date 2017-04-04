#pragma once
#include <stdint.h>

//__declspec(dllexport) uint32_t getBytesForAdpcmBuffer(uint32_t samples);
//__declspec(dllexport) uint32_t getBytesForAdpcmSamples(uint32_t samples);
//__declspec(dllexport) uint32_t getBytesForPcmBuffer(uint32_t samples);
//__declspec(dllexport) uint32_t getBytesForPcmSamples(uint32_t samples);
//__declspec(dllexport) uint32_t getNibbleAddress(uint32_t samples);
//__declspec(dllexport) uint32_t getNibblesForNSamples(uint32_t samples);
//__declspec(dllexport) uint32_t getSampleForAdpcmNibble(uint32_t nibble);
//__declspec(dllexport) uint32_t getBytesForAdpcmInfo(void);

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