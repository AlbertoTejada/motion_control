#ifndef PID_H 

#define PID_H 

#include <stdint.h>

// PID cyclic task time [ms]
#define PID_TASK_TIME 10U

// MIN and MAX macros for calculation support:
#ifndef MIN
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#endif
#ifndef MAX
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#endif

/**
 * Initilizes the PID. This function shall be
 * called once during the system.
 * initialization and shall be executed only once.
 * @return Error code, 0 if success.
 */
uint8_t init_pid(void);

/**
 * Updates the input variables.
 * @return Error code, 0 if success.
 */
uint8_t read_inputs(void);

/**
 * Verifies that the input value is in valid range.
 * If the input is below the minimum, sets it to 0.
 * If the input is above the maximum, sets it to the
 * corresponding limit.
 * @param[out] value - Value of the corresponding input.
 * @return Error code if the value is above the maximum.
 */
uint8_t check_inputs_limits(int32_t *value);

/**
 * Calculates the control signal for the given inputs.
 */
void pid(void);

/**
 * Writes the control signal adjusted according to the
 * parameters limit in the RTE.
 * @return error code, 0 if success.
 */
uint8_t write_outputs(void);

/**
 * Executes the PID cyclical task.
 * @return error code, 0 if success.
 */
uint8_t pid_task(void);

#endif // PID_H
