#pragma once

#ifndef RTE_MOCK_H
#define RTE_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"
#include "rte_pid_types.h"

class RteMock{
public:
	virtual ~RteMock(){}

	//Mock methods
	MOCK_METHOD(uint8_t, rte_pid_read_params, (PidParams* parameters));
	
	MOCK_METHOD(uint8_t, rte_pid_read_current_value, (int32_t* value));

	MOCK_METHOD(uint8_t, rte_pid_read_target_value, (int32_t* value));

	MOCK_METHOD(uint8_t, rte_pid_read_elapsed_time, (uint32_t* value));

	MOCK_METHOD(uint8_t, rte_pid_write_control_signal, (int32_t* value));
};

#endif // RTE_MOCK_H
