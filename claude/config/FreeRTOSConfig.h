#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*
 * Minimal kernel configuration. Every option is documented at
 * https://www.freertos.org/Documentation/02-Kernel/03-Supported-devices/02-Customization
 * Anything not set here falls back to the default in FreeRTOS.h.
 */

/* Scheduling */
#define configUSE_PREEMPTION                    1
#define configUSE_TIME_SLICING                  1
#define configTICK_RATE_HZ                      1000  /* 1 tick = 1 ms */
#define configMAX_PRIORITIES                    5
#define configIDLE_SHOULD_YIELD                 1

/* On a real MCU this is the CPU clock; the POSIX port ignores it. */
#define configCPU_CLOCK_HZ                      1000000

/* Memory */
#define configSUPPORT_DYNAMIC_ALLOCATION         1
#define configSUPPORT_STATIC_ALLOCATION          0
/* Each task's stack comes from this heap. On Linux, pthreads need big stacks
 * (PTHREAD_STACK_MIN words = 128 KB per task on 64-bit), hence the large heap.
 * On a microcontroller both numbers would be far smaller. */
#define configTOTAL_HEAP_SIZE                   ( 1024 * 1024 )
#define configMINIMAL_STACK_SIZE                ( ( unsigned short ) PTHREAD_STACK_MIN )
#define configMAX_TASK_NAME_LEN                 16

/* Hooks: all off to keep things minimal */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configUSE_MALLOC_FAILED_HOOK            0
#define configCHECK_FOR_STACK_OVERFLOW          0

/* Optional features */
#define configUSE_MUTEXES                       1
#define configUSE_TIMERS                        0
#define configUSE_TRACE_FACILITY                0
#define configUSE_16_BIT_TICKS                  0

/* Include the API functions we use */
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_vTaskDelete                     1

/* Catch programming errors: halt with a message instead of silently misbehaving. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  /* PTHREAD_STACK_MIN */
#define configASSERT( x )                                                   \
    do {                                                                    \
        if( !( x ) ) {                                                      \
            fprintf( stderr, "configASSERT failed: %s:%d\n", __FILE__, __LINE__ ); \
            abort();                                                        \
        }                                                                   \
    } while( 0 )

#endif /* FREERTOS_CONFIG_H */
