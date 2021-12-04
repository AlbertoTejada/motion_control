#include "pid.h"
#include "error_codes.h"
#include "rte_pid.h"
#include <stdint.h>

// Global variables definitions:
// Current value of the system under control [not def unis]
int32_t current_value;
// Target value of the system under control [not def units]
int32_t target_value;
// External timer value for error calculation [no units]
uint32_t elapsed_time;
// Control signal for the system actuator [not def units]:
int32_t control_signal;
// PID parameters:
PidParams parameters;

uint8_t init_pid(void){
        uint8_t result;
        current_value = 0u;
        target_value = 0u;
        elapsed_time = PID_TASK_TIME;
        control_signal = 0u;
        result = rte_pid_read_params(&parameters);
        return result;
}

uint8_t read_inputs(void){
        uint8_t result = rte_pid_read_target_value(&target_value);
        if (result == ERR_OK){
                check_inputs_limits(&target_value);
                result = rte_pid_read_current_value(&current_value);
        }
        if (result == ERR_OK){
                result = check_inputs_limits(&current_value);
        }
        if (result == ERR_OK){
                result = rte_pid_read_elapsed_time(&elapsed_time);
        }
        return result;
}

uint8_t check_inputs_limits(int32_t *value){
        uint8_t result = ERR_OK;
        if ((*value < parameters.i_pos_min) &
            (*value > -parameters.i_neg_min)){
                *value = 0;
        }else if (*value > parameters.i_pos_max){
                *value = parameters.i_pos_max;
                result = ERR_OUT_RANGE;
        }else if (*value < parameters.i_pos_min){
                *value = -parameters.i_neg_max;
                result = ERR_OUT_RANGE;
        }
       return result; 
}

void pid(void){
        static int32_t error_0 = 0;
        static float i_error = 0.0;

        int32_t error = target_value - current_value;
        float d_error = (float)(error - error_0) / (float)elapsed_time;
        i_error += (float)(error * (int32_t)elapsed_time);
        error_0 = error;

        float p = parameters.p * error;
        float i = parameters.i * i_error;
        float d = parameters.d * d_error; 
        if ((p + i + d) > (float)INT32_MAX){
                control_signal = INT32_MAX;
        } else if ((p + i + d) < (float)INT32_MIN){
                control_signal = INT32_MIN;
        } else {
                control_signal = (int32_t)(p + i + d);
        }
}

uint8_t write_outputs(void){
        control_signal = MIN(control_signal,
                             parameters.o_pos_max);
        control_signal = MAX(control_signal,
                             -parameters.o_neg_max);
        if ((control_signal < parameters.o_pos_min) &&
            (control_signal > -parameters.o_neg_min)) {
                control_signal = 0;
        }

        rte_pid_write_control_signal(&control_signal);

        return ERR_OK;
}

uint8_t pid_task(void){
        uint8_t result;
        result= read_inputs();
        if(result == ERR_OK) {
                pid();
        } else {
                control_signal = 0;
        }
        write_outputs();
        return result;
}
