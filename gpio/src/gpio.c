#include "gpio.h"
#include "board.h"

void init(void) {
   // Configure the CAN driver CS pin as output:
   CAN_DVR_CS_DIR |= (OUTPUT << CAN_DVR_CS); 
   CAN_DVR_CS_PORT |= (1 << CAN_DVR_CS);
   // Configure the power motor activation pin as output:
   MOTOR_ACTIVATION_DIR |= (OUTPUT << MOTOR_ACTIVATION);
   MOTOR_ACTIVATION_PORT &= ~(1 << MOTOR_ACTIVATION);
   // Configure the power motor spin direction pin as output:
   MOTOR_SPIN_DIR |= (OUTPUT << MOTOR_SPIN);
   MOTOR_SPIN_PORT &= ~(1 << MOTOR_SPIN);
}

void can_drv_select(void){
   CAN_DVR_CS_PORT &= ~(1 << CAN_DVR_CS);
}

void can_drv_deselect(void){
   CAN_DVR_CS_PORT |= (1 << CAN_DVR_CS);
}

void power_motor_activate(void){
   MOTOR_ACTIVATION_PORT |= (1 << MOTOR_ACTIVATION);
}

void power_motor_deactivate(void){
   MOTOR_ACTIVATION_PORT &= ~(1 << MOTOR_ACTIVATION);
}

void power_motor_forward(void){
   MOTOR_SPIN_PORT &= ~(1 << MOTOR_SPIN);
}

void power_motor_backward(void){
   MOTOR_SPIN_PORT |= (1 << MOTOR_SPIN);
}
