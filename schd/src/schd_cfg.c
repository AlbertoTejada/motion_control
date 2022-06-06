#include "schd_cfg.h"
#include "schd.h"

/* volatile uint8_t cycles = 1; */
extern uint8_t task_10_ms_flag;
extern uint8_t task_100_ms_flag;

ISR(TIMER2_COMPA_vect) {
	/* cycles++; */
	// Execute the task
	task_10_ms_flag = 1;
}

ISR(TIMER2_COMPB_vect) {
	task_100_ms_flag = 1;
	/* switch(cycles) */
	/* { */
	/* 	case 1: */
	/* 		// Execute the task */
	/* 		task_100_ms_flag = 1; */
	/* 		break; */
	/* 	case (SCHD_TASK_B_TIME/SCHD_TASK_A_TIME): */
	/* 		// Reset the cycles counter */
	/* 		cycles = 0; */
	/* 		break; */
	/* 	default: */
	/* 		break; */
	/* } */
}

void schd_empty_task(void) {
}

