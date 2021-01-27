#ifndef MOTOR_PINS_H
#define MOTOR_PINS_H

// ***
// *** These are the pin assignments for the
// *** connection to the A4988 board.
// ***

#ifdef E-MOTOR
  #define MOTOR_NAME "E Motor"
  #define MOTOR_STEP_PIN 1
  #define MOTOR_DIRECTION_PIN 0
  #define MOTOR_EN 14
#endif

#ifdef Z-MOTOR
  #define MOTOR_NAME "Z Motor"
  #define MOTOR_STEP_PIN 3
  #define MOTOR_DIRECTION_PIN 2
  #define MOTOR_EN 26
#endif

#ifdef X-MOTOR
  #define MOTOR_NAME "X Motor"
  #define MOTOR_STEP_PIN 15
  #define MOTOR_DIRECTION_PIN 21
  #define MOTOR_EN 14
#endif

#ifdef Y-MOTOR
  #define MOTOR_NAME "Y Motor"
  #define MOTOR_STEP_PIN 22
  #define MOTOR_DIRECTION_PIN 23
  #define MOTOR_EN 14
#endif

#endif
