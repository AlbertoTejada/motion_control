Motion Control System

![Unit Tests](https://github.com/AlbertoTejada/motion_control/actions/workflows/unit_tests.yml/badge.svg)

This is a Embedded C project designed for an ATmega328p microcontroller that intends to provide a simple CAN interface to control an electric autonomous RC car.

The system provides two controllers:
- A close loop PID speed control for a DC motor with an encoder that will be the engine.
- An open loop position control for a servo motor that will be the steering wheel. 

The input for the controllers will be cyclically updated by a CAN message from the master controller. The speed value and steering angle will be cyclically reported in a CAN message to the rest of the systems on the bus.
