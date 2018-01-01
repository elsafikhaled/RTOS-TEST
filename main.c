#include "UART.h"
#include "FreeRTOS.h"
#include "task.h"

void T_usart(void*ptrToPara);
void T_usart2(void*ptrToPara);


int main(void){
	
//system initialization.	
	Uart1_Init();
	UART1_SendString((unsigned char*)"UART START\n");
	xTaskCreate(T_usart,"SERIAL",100,NULL,8,NULL);
	UART1_SendString((unsigned char*)"TASK 1 Created \n");
  xTaskCreate(T_usart2,"SERIAL2",100,NULL,9,NULL);
	UART1_SendString((unsigned char*)"TASK 2 Created \n");

	vTaskStartScheduler();

	while(1);
}

void T_usart(void*ptrToPara)
{ 
	for(;;)
	{ 
		UART1_SendString((unsigned char*)"TASK 1 STARTED\n");
	}
	
}

void T_usart2(void*ptrToPara)
{ 
	for(;;)
	{ 
		UART1_SendString((unsigned char*)"TASK 2 STARTED\n");
	}
	
}
