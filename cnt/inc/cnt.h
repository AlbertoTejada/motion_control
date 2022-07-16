#pragma once

#ifndef CNT_H
#define CNT_H

#include <stdint.h>

// Disable OCR0A and OCRB for normal mode:
#define CNT_NORMAL_MODE (0x00) 
// Set the Wave Generation to normal:
#define CNT_WGM (0x00)
// Set the clock selection to external clock
// on T0 and clock on rising edge
#define CNT_CS_T0 (0x07)
// Enable the overflow interruption
#define CNT_OVFW_ENBL (0x01)
/* #define CNT_EXT_CLK 1 */
/* #define CNT_ASYC_ENBL 1 */
#define CNT_CTRLA_CFG ( CNT_NORMAL_MODE + \
												CNT_WGM )
#define CNT_CTRLB_CFG ( CNT_CS_T0 )
#define CNT_IMASK_CFG ( CNT_OVFW_ENBL )

void cnt_init(void);

uint8_t read_cnt(void);

uint8_t cnt_over_flow(void);

#endif // CNT_H
