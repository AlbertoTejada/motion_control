/**
 * \brief Simple test to toggle the GPIO AVR output.
 *
 * \file gpio_test.c
 * \author Alberto Tejada
 */

#include "gpio.h"
#include <util/delay.h>

/**
 * \brief GPIO on target test.
 * This is a simple test to verify the behaviour of the GPIO
 * pins. The expected result shall be:
 * Each 100ms the CAN_DRV_CS pin (D10) toggles.
 * Each 200ms the motor activation pin (D07) toggles.
 * Each 300ms the motor spin pin (D04) toggles.
 */
int main(void)
{
   gpio_init();
   _delay_ms(5000);

   while(1)
   {
      can_drv_select();
      power_motor_activate();
      power_motor_backward();
      _delay_ms(100);
      can_drv_deselect();
      _delay_ms(100);
      can_drv_select();
      power_motor_deactivate();
      _delay_ms(100);
      can_drv_deselect();
      power_motor_forward();
      _delay_ms(100);
      can_drv_select();
      power_motor_activate();
      _delay_ms(100);
      can_drv_deselect();
      _delay_ms(100);
      can_drv_select();
      power_motor_deactivate();
      power_motor_backward();
      _delay_ms(100);
      can_drv_deselect();
      _delay_ms(100);
      can_drv_select();
      power_motor_activate();
      _delay_ms(100);
      can_drv_deselect();
      power_motor_forward();
      _delay_ms(100);
      can_drv_select();
      power_motor_deactivate();
      _delay_ms(100);
      can_drv_deselect();
      _delay_ms(100);
   }
}

