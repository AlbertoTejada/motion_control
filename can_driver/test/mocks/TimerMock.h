#pragma once

#ifndef _TIMER_MOCK_H_
#define _TIMER_MOCK_H_

#include <stdint.h>
#include "gmock/gmock.h"

class TimerMock{
	public:
		virtual ~TimerMock(){}

		// Mock methods
		MOCK_METHOD(uint32_t, os_timer_ms, ());

		MOCK_METHOD(uint32_t, os_timer_us, ());

		MOCK_METHOD(void, os_wait_ms, (uint16_t));
};
#endif // _TIMER_MOCK_H_
