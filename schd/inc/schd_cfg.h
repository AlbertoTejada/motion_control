#ifndef SCHD_CFG_H
#define SCHD_CFG_H

#include "board.h"
#include <avr/interrupt.h>

// Time in ms for the task A:
#define SCHD_TASK_A_TIME 10
// Time in ms for the task B (it must ba a multiple of
// task A)
#define SCHD_TASK_B_TIME 100

/* #define SCHD_MILLIS(TIME, PRES) ((TIME * PRES) / OSC_FREQUENCY) */
#define SCHD_MILLIS(TIME, PRES) (((OSC_FREQUENCY / 1000) / PRES) * TIME)

void task_10_ms_cgf(void);

void task_100_ms_cgf(void);

void schd_empty_task(void);

#endif // SCHD_CFG_H
