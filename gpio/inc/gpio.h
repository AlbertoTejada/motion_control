#ifndef GPIO_H 
#define GPIO_H

/**
 * \brief Initializes the GPIO pins and sets them to
 * low value.
 */
void gpio_init(void);

/**
 * \brief Activates the CAN controller SPI
 */
void can_drv_select(void);

/**
 * \brief Deactivates the CAN controller SPI
 */
void can_drv_deselect(void);

/**
 * \brief Activates the power motor
 */
void power_motor_activate(void);

/**
 * \brief Deactivates the power motor
 */
void power_motor_deactivate(void);

/**
 * \brief Set the power motor spin direction forward 
 */
void power_motor_forward(void);

/**
 * \brief Set the power motor spin direction backward 
 */
void power_motor_backward(void);

#endif // GPIO_H
