#include "uart.h"
#include <util/delay.h>

int main(void){
	char test[] = "Hello World! 0\n";
	uint8_t idx = 0;
	uint8_t len = 15;
	uint8_t input; 

	uart_init();

	while(1){
		uart_tx(test[idx]);
		idx++;
		if(idx == len)
		{
			idx = 0;
			if(uart_rx(&input))
			{
				test[13] = input;
			}
		}
		_delay_ms(200);
	}
  return 0;
}

