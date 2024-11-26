#include "FreeRTOS.h"
#include "task.h"
#include "xil_printf.h"
#include "xparameters.h"

#define DELAY_5s	5000UL
#define DELAY_1s	1000UL


//Thread implementation
static void myTask1(void *);
static void myTask2(void *);


//Task Handle
static TaskHandle_t th_myTask1;
static TaskHandle_t th_myTask2;



int main( void )
{

	xil_printf( "My first FreeRTOS app\n" );


	xTaskCreate(myTask1,
			    (const char *) "myTask1",
				configMINIMAL_STACK_SIZE,
				NULL,
				tskIDLE_PRIORITY,
				&th_myTask1);

	xTaskCreate(myTask2,
				(const char *) "myTask2",
				configMINIMAL_STACK_SIZE,
				NULL,
				tskIDLE_PRIORITY,
				&th_myTask2);

    // Start the Task
	vTaskStartScheduler();


	while(true);
}




static void myTask1(void* pvParameters)
{
  unsigned int count = 0;

  while(1)
  {
	  vTaskDelay(pdMS_TO_TICKS(DELAY_1s));
	  count++;
	  xil_printf("Thread 1 counter value: %u \r\n", count);
  }

}


static void myTask2(void* pvParameters)
{
  unsigned int count = 0;

  while(1)
  {
	  vTaskDelay(pdMS_TO_TICKS(DELAY_5s));
	  count++;
	  xil_printf("Thread 2 counter value: %u \r\n", count);
  }

}