#ifndef ADC_H
#define ADC_H

#include <stdint.h>

#define ADC_VREF (1 << 6)
#define ADC_ENBL (1 << 7)
#define ADC_STRT (1 << 6)
#define ADC_PRES (3)
#define ADC_PINS (0x3E)

void adc_init(void);

uint16_t read_angle(void);

#endif // ADC_H
