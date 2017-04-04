#pragma once
#include <stdint.h>

uint32_t getBytesForAdpcmBuffer(uint32_t samples);
uint32_t getBytesForAdpcmSamples(uint32_t samples);
uint32_t getBytesForPcmBuffer(uint32_t samples);
uint32_t getBytesForPcmSamples(uint32_t samples);
uint32_t getNibbleAddress(uint32_t samples);
uint32_t getNibblesForNSamples(uint32_t samples);
uint32_t getSampleForAdpcmNibble(uint32_t nibble);
uint32_t getBytesForAdpcmInfo(void);