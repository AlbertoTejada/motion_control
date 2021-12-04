#ifndef RTE_PID_H

#define RTE_PID_H

#include <stdint.h>
#include "rte_pid_types.h"

/**
 * Read the PID parameters from the system memory.
 * @param [out] parameters - PID parameters structure
 * @return Error code, 0 if success
 */
uint8_t rte_pid_read_params(PidParams *parameters);

/**
 * Read the current value of the system under control 
 * @param [out] value - Current value 
 * @return Error code, 0 if success
 */
uint8_t rte_pid_read_current_value(int32_t *value);

/**
 * Read the target value of the system under control 
 * @param [out] value - Target value 
 * @return Error code, 0 if success
 */
uint8_t rte_pid_read_target_value(int32_t *value);

/**
 * Read the elapsed time from the previous sample 
 * @param [out] value - Elapased time
 * @return Error code, 0 if success
 */
uint8_t rte_pid_read_elapsed_time(uint32_t *value);

/**
 * Write the control signal calculated
 * @param [in] value - Control singal
 * @return Error code, 0 if success
 */
uint8_t rte_pid_write_control_signal(int32_t *value);

#endif // RTE_PID_H 
