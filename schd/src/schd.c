#include "schd.h"
#include "schd_cfg.h"

void (*task_10_ms_ptr)(void);
void (*task_100_ms_ptr)(void);
volatile uint8_t task_10_ms_flag = 0;
volatile uint8_t task_100_ms_flag = 0;

void schd_init(void) {
	// Set the clock input:
	SCHD_ASYC = (SCHD_EXT_CLK << EXCLK);
	SCHD_ASYC |= (SCHD_ASYC_ENBL << AS2);
	// Set compare match pins and the operation mode:
	SCHD_CTRLA = (SCHD_COMPA_PIN << COM2A0)
		         | (SCHD_COMPB_PIN << COM2B0)
						 | (SCHD_OP_MODE << WGM20);
	// Set the counter prescaler: 
	SCHD_CTRLB = (SCHD_CLK_PRES << CS20);
	// Enable the overflow interrupt flag:
	SCHD_IMASK = (SCHD_INT_COMPA << OCIE2A)
		         | (SCHD_INT_COMPB << OCIE2B)
						 | (SCHD_INT_OVRFL << TOIE2);
	// Set the timer value for the task A:
	SCHD_TIMEA = SCHD_MILLIS(SCHD_TASK_A_TIME, 1024);
	// Set the shift time for the task B:
	SCHD_TIMEB = SCHD_MILLIS(SCHD_TASK_B_SHFT, 1024);
	// Initalize the tasks to an empty value:
  task_10_ms(schd_empty_task);
	task_100_ms(schd_empty_task);
	// Enable Global Interrupts:
	sei();
}

void task_10_ms(void (*task)(void)) {
	task_10_ms_ptr = task;
}

void task_100_ms(void (*task)(void)) {
	task_100_ms_ptr = task;	
}

void scheduler(void) {
	if(task_10_ms_flag) {
		(*task_10_ms_ptr)();
		task_10_ms_flag = 0;
	}
	if(task_100_ms_flag) {
		(*task_100_ms_ptr)();
		task_100_ms_flag = 0;
	}
}

