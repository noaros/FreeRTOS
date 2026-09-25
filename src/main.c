/*
 * Bare-bones FreeRTOS application.
 *
 * Two tasks talk through a queue:
 *   - producer: every 500 ms sends an incrementing counter to the queue
 *   - consumer: blocks on the queue and prints whatever arrives
 *
 * This shows the three things nearly every FreeRTOS program does:
 * create tasks, share data safely between them, and start the scheduler.
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define QUEUE_LENGTH      5
#define TASK_STACK_SIZE   configMINIMAL_STACK_SIZE
#define PRODUCER_PRIORITY ( tskIDLE_PRIORITY + 1 )
#define CONSUMER_PRIORITY ( tskIDLE_PRIORITY + 2 )

static QueueHandle_t xQueue;

static void vProducerTask( void * pvParameters )
{
    ( void ) pvParameters;
    uint32_t ulCount = 0;

    for( ;; )
    {
        ulCount++;
        printf( "[producer] sending %lu\n", ( unsigned long ) ulCount );

        /* Wait up to 0 ticks if the queue is full (i.e. don't wait). */
        xQueueSend( xQueue, &ulCount, 0 );

        /* Block this task for 500 ms, letting others run. */
        vTaskDelay( pdMS_TO_TICKS( 500 ) );
    }
}

static void vConsumerTask( void * pvParameters )
{
    ( void ) pvParameters;
    uint32_t ulReceived;

    for( ;; )
    {
        /* Block forever until something arrives. The consumer has the higher
         * priority, so it runs the moment the producer sends. */
        if( xQueueReceive( xQueue, &ulReceived, portMAX_DELAY ) == pdPASS )
        {
            printf( "[consumer] got     %lu\n", ( unsigned long ) ulReceived );
        }
    }
}

int main( void )
{
    /* Disable stdout buffering so output from different tasks shows up immediately. */
    setvbuf( stdout, NULL, _IONBF, 0 );

    xQueue = xQueueCreate( QUEUE_LENGTH, sizeof( uint32_t ) );
    configASSERT( xQueue != NULL );

    xTaskCreate( vProducerTask, "producer", TASK_STACK_SIZE, NULL, PRODUCER_PRIORITY, NULL );
    xTaskCreate( vConsumerTask, "consumer", TASK_STACK_SIZE, NULL, CONSUMER_PRIORITY, NULL );

    /* Hand control to the kernel. This only returns if there wasn't enough
     * heap to create the idle task. */
    vTaskStartScheduler();

    printf( "Scheduler failed to start\n" );
    for( ;; )
    {
    }
}
