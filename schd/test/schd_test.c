#include "schd.h"
#include "uart.h"
#include <util/delay.h>

void task_1(void);
void task_2(void);

/* char str_task_1[] = "10 ms task\n"; */
/* char str_task_2[] = "--> 100 ms task\n"; */
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

