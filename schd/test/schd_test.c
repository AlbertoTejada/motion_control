/**
 * \brief Simple test to verify the scheduler feature
 *
 * \file schd_test.c
 * \author Alberto Tejada
 */

#include "schd.h"
#include "uart.h"
#include <util/delay.h>

/**
 * \brief Scheduler on target test:
 * This is the simplest way to verify that the scheduler is
 * correctly configured on target.
 * In order to execute this test, the UART communication must
 * be enabled with the test machine.
 * The expected behaviour is that the `str_task_1` string is
 * received through the UART each 10 ms and the `str_task_2`
 * is received each 100 ms.
 *
 * \note
 * Some performance issues have been observed in this
 * feature. For an unknown reason, the scheduler struggles
 * with strings longer than 6 characters, which is far below
 * the expected limit.
 */

void task_1(void);
void task_2(void);

char str_task_1[] = "-----1\n";
char str_task_2[] = "+++++2\n";

int main(void){

	schd_init();
	uart_init();

	char init_str[] = "Starting the scheduler\n";
	uint8_t idx = 0;

	while(init_str[idx] != '\n'){
		uart_tx(init_str[idx]);
		idx++;
	}
	uart_tx('\n');
	idx = 0;

	task_10_ms(&task_1);
	task_100_ms(&task_2);

	while(1){
		scheduler();
	}

	return 0;
}

void task_1(void) {
	uint8_t idx = 0;
	while(str_task_1[idx] != '\n'){
		uart_tx(str_task_1[idx]);
		idx++;
	} 
	uart_tx('\n');
}

void task_2(void) {
	uint8_t idx = 0;
	while(str_task_2[idx] != '\n'){
		uart_tx(str_task_2[idx]);
		idx++;
	} 
	uart_tx('\n');
}

