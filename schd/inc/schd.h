#pragma once

#ifndef SCHD_H
#define SCHD_H

#include <stdint.h>

// Shift time in ms between task A and B executions
#define SCHD_TASK_B_SHFT 5
// Operation mode of the counter CTC
#define SCHD_OP_MODE 2
// Behaviour of the Compare A match PIN
#define SCHD_COMPA_PIN 0
// Behaviour of the Compare B match PIN
#define SCHD_COMPB_PIN 0
// Clock preescaler
#define SCHD_CLK_PRES 7
// Interruption on Compare A match mask
#define SCHD_INT_COMPA 1
// Interruption on Compare B match mask
#define SCHD_INT_COMPB 1
// Interruption on Counter Overflow mask
#define SCHD_INT_OVRFL 0
// Selection for external clock
#define SCHD_EXT_CLK 0
// Selection of asynchronous mode
#define SCHD_ASYC_ENBL 0

void schd_init(void);

void task_10_ms(void (*task)(void));

void task_100_ms(void (*task)(void));

void scheduler(void);

#endif // SCHD_H
