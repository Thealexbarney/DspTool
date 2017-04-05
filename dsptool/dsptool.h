#pragma once
#ifdef __cplusplus  
extern "C" {
#endif 

#include <stdint.h>

#define BYTES_PER_FRAME 8
#define SAMPLES_PER_FRAME 14
#define NIBBLES_PER_FRAME 16

#ifdef COMPILING_DLL  
#define DLLEXPORT __declspec(dllexport)  
#else  
#define DLLEXPORT __declspec(dllimport)  
#endif

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

DLLEXPORT void encode(int16_t* src, uint8_t* dst, ADPCMINFO *cxt, uint32_t samples);
DLLEXPORT void decode(uint8_t* src, int16_t* dst, ADPCMINFO *cxt, uint32_t samples);
DLLEXPORT void getLoopContext(uint8_t *src, ADPCMINFO *cxt, uint32_t samples);

DLLEXPORT uint32_t getBytesForAdpcmBuffer(uint32_t samples);
DLLEXPORT uint32_t getBytesForAdpcmSamples(uint32_t samples);
DLLEXPORT uint32_t getBytesForPcmBuffer(uint32_t samples);
DLLEXPORT uint32_t getBytesForPcmSamples(uint32_t samples);
DLLEXPORT uint32_t getNibbleAddress(uint32_t samples);
DLLEXPORT uint32_t getNibblesForNSamples(uint32_t samples);
DLLEXPORT uint32_t getSampleForAdpcmNibble(uint32_t nibble);
DLLEXPORT uint32_t getBytesForAdpcmInfo(void);

#ifdef __cplusplus  
}
#endif  