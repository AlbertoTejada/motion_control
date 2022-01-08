#include "adc.h"
#include "board.h"


void adc_init(void){
	// Configure the steering wheel motor sensor as input	
	STEERING_SENS_DIR = 0;
	// Configure the ADC Vref as Vcc with external capacitor
	// at Aref and set the multiplexer to ADC0
	ADC_MUX = ADC_VREF;
	// Enable the ADC and set the prescaler to 128
	ADC_CTRLA = ADC_ENBL
		| ADC_PRES;
	// Disable the input buffer on all the pins except ADC0
	ADC_DISB = ADC_PINS;
	// Perform an initial conversion to initialise the ADC
	read_angle();
}

uint16_t read_angle(void){
	// Start the conversion
	// TODO: Conversion can be triggered by the scheduler,
	ADC_CTRLA |= ADC_STRT;

	uint16_t result;

	while(ADC_CTRLA & ADC_STRT);

	result = ADC_DATAL;
	result |= ADC_DATAH << 8;

	return result;
}
