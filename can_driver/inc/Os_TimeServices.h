#pragma once

#ifndef _TIME_SERVICES_H_
#define _TIME_SERVICES_H_

#include <stdint.h>

/* #if defined(__cplusplus) */
/* extern "C" */
/* { */
/* #endif */

uint32_t os_timer_ms(void);

uint32_t os_timer_us(void);

void os_wait_ms(uint16_t);

/* #if defined(__cplusplus) */
/* } // Closing brace for extern C */
/* #endif */

#endif // _TIME_SERVICES_H_


