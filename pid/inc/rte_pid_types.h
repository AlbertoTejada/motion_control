#ifndef RTE_PID_TYPES_H

#define RTE_PID_TYPES_H

#include <stdint.h>

typedef struct {
	float p;
	float i;
	float d;
	uint16_t i_pos_min; 
  uint16_t i_neg_min;
  uint16_t i_pos_max;
  uint16_t i_neg_max;
  uint16_t o_pos_min;
  uint16_t o_neg_min;
  uint16_t o_pos_max;
  uint16_t o_neg_max;
	uint8_t calibrated;
}PidParams; 

#endif // RTE_PID_TYPES_H
