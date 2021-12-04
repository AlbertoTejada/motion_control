#include "Fixture.h"
extern "C" {
#include "rte_pid.h"
}

extern "C" uint8_t rte_pid_read_params(PidParams* parameters){
	return Fixture::_rte -> rte_pid_read_params(parameters);
}

extern "C" uint8_t rte_pid_read_current_value(int32_t* parameters){
	return Fixture::_rte -> rte_pid_read_current_value(parameters);
}

extern "C" uint8_t rte_pid_read_target_value(int32_t* parameters){
	return Fixture::_rte -> rte_pid_read_target_value(parameters);
}

extern "C" uint8_t rte_pid_read_elapsed_time(uint32_t* parameters){
	return Fixture::_rte -> rte_pid_read_elapsed_time(parameters);
}

extern "C" uint8_t rte_pid_write_control_signal(int32_t* parameters){
	return Fixture::_rte -> rte_pid_write_control_signal(parameters);
}
