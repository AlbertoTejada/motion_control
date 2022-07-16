#include "cnt.h"
#include "board.h"

void cnt_init(void) {
	/* // Set the external asynchronous clock input: */
	/* CNT_ASYC = (CNT_EXT_CLK << 6); */
	/* CNT_ASYC |= (CNT_ASYC_ENBL << 5); */
	// Disconnect compare registers A and B
	// and set normal mode of operation
	/* CNT_CTRLA = CNT_NORMAL_MODE; */
	CNT_CTRLA = CNT_CTRLA_CFG;
	// Set the counter prescaler to 1 (no prescaling)
	/* CNT_CTRLB = CNT_NO_PRSCLR; */
	CNT_CTRLB = CNT_CTRLB_CFG;
	// Enable the overflow interrupt flag
	CNT_IMASK = CNT_IMASK_CFG;
}

uint8_t read_cnt(void) {
	return CNT_DATA;
}

uint8_t cnt_over_flow(void) {
	uint8_t ovfw = CNT_IFLAG & CNT_OVFW_ENBL;
	CNT_IFLAG = CNT_IFLAG & 0xFE;
	return ovfw;
}

