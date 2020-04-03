// ----------------------------------------------------------------------------+
//
//	Double Buffer example
//
//	This example shows how to use the DMA Half-Complete-Callback and the
//	Complete-Callback to avoid simultaneously reading from and writing to
//	a certain buffer.
//
//	When the Half-Complete ISR is called, data from PART1 can safely be read
//	while PART2 is being written to. When the Complete ISR is called, data from
//	PART 2 is read, while the DMA writes to PART 1.
//
//	                       |                     |
//	+---------------------+|+-------------------+|
//	|        PART1        |||      PART2        ||
//	+---------------------+|+-------------------+|
//	                       |                     |
//	                       HALF-COMPLETE         COMPLETE   
//
// ----------------------------------------------------------------------------+

#include <stdio.h>	// memcpy

#define BUFFER 100
uint32_t adc_input[2*BUFFER];
uint32_t dac_output[2*BUFFER]

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
	memcpy(dac_output, adc_input, BUFFER*sizeof(adc_input[0]));
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	memcpy(dac_output+FILTER_BUFFER, adc_input+BUFFER, BUFFER*sizeof(adc_input[0]));
}
