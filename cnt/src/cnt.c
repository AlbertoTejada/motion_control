#include "cnt.h"
#include "board.h"

void cnt_init(void) {
	// Set the external asynchronous clock input:
	CNT_ASYC = (CNT_EXT_CLK << 6);
	CNT_ASYC |= (CNT_ASYC_ENBL << 5);
	// Disconnect compare registers A and B
	// and set normal mode of operation
	CNT_CTRLA = CNT_NORMAL_MODE;
	// Set the counter prescaler to 1 (no prescaling)
	CNT_CTRLB = CNT_NO_PRSCLR;
	// Enable the overflow interrupt flag
	CNT_IMASK = CNT_OVFW_ENBL;
}

uint8_t read_cnt(void) {
	return CNT_DATA;
}
