// This file is only for testing propose. It's goal is to
// allow the tester to read the global variables defined
// in the  source code.

#include <stdint.h>
#include "rte_pid_types.h"

extern int32_t current_value;
extern int32_t target_value;
extern uint32_t elapsed_time;
extern int32_t control_signal;
extern PidParams parameters;
