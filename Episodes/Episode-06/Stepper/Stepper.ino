/*
  MIT License
  
  Copyright (c) 2021 Daniel Porrey
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
#include <SpeedyStepper.h>

// ***
// *** Uncomment one of the lines below to select 
// *** the motor connection.
// ***
#define E-MOTOR
//#define Z-MOTOR
//#define X-MOTOR
//#define Y-MOTOR

#include "MotorPins.h"

// ********************************************************
// ********************************************************
// *** Motor Wiring
// ***
// *** Motors will differ in wiring. Buy motors that include
// *** a datasheet or a pin diagram. For example, my motor
// *** (NEMA 17 bipolar) describes the pins as 4-wire:
// *** Black: A+, Green: A-, Red: B+, Blue: B-
// ***
// *** My wiring is as follows:
// ***   A+ to 2B
// ***   A- to 2A
// ***   B+ to 1A
// ***   B- to 1B
// ***
// *** This results in 
// ***   Forward = Clockwise
// ***   Reverse = Counterclockwise
// ***
// ********************************************************
// ********************************************************

// ***
// *** Motor steps for 1 full revolution.
// ***
#define STEPS 200

// ***
// *** Define the microstep configure. This depends on the values of
// *** the MSn pins on the A4988 board.
// ***
// ***  MS1   MS2   MS3   Microstep    MICROSTEP
// ***                    Resolution   Value
// ***  ========================================
// ***  LOW   LOW   LOW   Full step      1
// ***  HIGH  LOW   LOW   1/2 step       2
// ***  LOW   HIGH  LOW   1/4 step       4
// ***  HIGH  HIGH  LOW   1/8 step       8
// ***  HIGH  HIGH  HIGH  1/16 step     16
// ***
#define MICROSTEPS 16

// ***
// *** Define the number of seconds to
// *** pause between moves.
// ***
#define PAUSE_BETWEEN_MOVES 2

// ***
// *** Create the SpeedyStepper instance.
// ***
SpeedyStepper stepper;

void setup()
{
  // ***
  // *** Initialize the serial port.
  // ***
  Serial.begin(500000);

  // ***
  // *** Wait for serial port to connect.
  // ***
  while (!Serial) {}
  Serial.println("Serial port initialized.");

  // ***
  // *** Connect and configure the SpeedyStepper instance.
  // ***
  Serial.println("Configurating to stepper motor driver.");
  stepper.connectToPins(MOTOR_STEP_PIN, MOTOR_DIRECTION_PIN);

  // ***
  // *** Set the number of steps per revolution.
  // ***
  stepper.setStepsPerRevolution(STEPS * MICROSTEPS);

  // ***
  // *** Set the speed and acceleration rates for the stepper motor
  // *** 60 RPM (1 rotation per second).
  // ***
  stepper.setSpeedInRevolutionsPerSecond(1.0);
  stepper.setAccelerationInRevolutionsPerSecondPerSecond(1.0);
  Serial.println("Stepper motor driver configuration completed.");
  Serial.print("Connected to: "); Serial.println(MOTOR_NAME);
  
  // ***
  // *** Setup has completed.
  // ***
  Serial.println("Ready.");
}

void loop()
{
  // ***
  // *** All moves are started at the motor's current position. The calls
  // *** to move the stepper will not return until the motion is complete.
  // ***
  Serial.println("Demonstrating relative moves.");
  demonstrateRelativeMoves();

  // ***
  // *** The motor's starting position is 0. A calls set a value that is based
  // *** on this starting point. The calls to move the stepper will not
  // *** return until the motion is complete.
  // ***
  Serial.println("Demonstrating absolute moves.");
  demonstrateAbsoluteMoves();

  // ***
  // *** The rotation has completed. pause for 5 seconds before
  // *** repeating the sequence.
  // ***
  Serial.println("Pausing for 5 seconds.");
  delay(5000);
}

void demonstrateRelativeMoves()
{
  // ***
  // *** Rotate the motor in the forward direction one revolution
  // *** and pause.
  // ***
  Serial.println("Rotating 1 full forward turn.");
  stepper.moveRelativeInRevolutions(1.0);
  delay(PAUSE_BETWEEN_MOVES * 1000);

  // ***
  // *** Rotate the stepper in the opposte direction one
  // *** full revolution and pause.
  // ***
  Serial.println("Rotatin 1 full reverse turn.");
  stepper.moveRelativeInRevolutions(-1.0);
  delay(PAUSE_BETWEEN_MOVES * 1000);

  // ***
  // *** Rotate the motor in the forward direction a half
  // *** revolution and pause.
  // ***
  Serial.println("Rotating 1/2 forward turn.");
  stepper.moveRelativeInRevolutions(.5);
  delay(PAUSE_BETWEEN_MOVES * 1000);
  
  // ***
  // *** Rotate the stepper in the opposite direction a
  // *** half revolution and pause.
  // ***
  Serial.println("Rotating 1/2 reverse turn.");
  stepper.moveRelativeInRevolutions(-.5);
  delay(PAUSE_BETWEEN_MOVES * 1000);
}

void demonstrateAbsoluteMoves()
{
  // ***
  // *** Move the motor to position .500 and pause.
  // ***
  Serial.println("Moving to position .500.");
  stepper.moveToPositionInRevolutions(.500);
  delay(PAUSE_BETWEEN_MOVES * 1000);

  // ***
  // *** Move the motor to .650 and pause.
  // ***
  Serial.println("Moving to position .650.");
  stepper.moveToPositionInRevolutions(.650);
  delay(PAUSE_BETWEEN_MOVES * 1000);

  // ***
  // *** Move the motor to .765 and pause.
  // ***
  Serial.println("Moving to position .765.");
  stepper.moveToPositionInRevolutions(.765);
  delay(PAUSE_BETWEEN_MOVES * 1000);

  // ***
  // *** Move the motor to .085 and pause.
  // ***
  Serial.println("Moving to position .085.");
  stepper.moveToPositionInRevolutions(.085);
  delay(PAUSE_BETWEEN_MOVES * 1000);

  // ***
  // *** Move the motor to .160 and pause.
  // ***
  Serial.println("Moving to position .160.");
  stepper.moveToPositionInRevolutions(.160);
  delay(PAUSE_BETWEEN_MOVES * 1000);

  // ***
  // *** Move the motor to 0 and pause. The motor
  // *** should be back to the starting point.
  // ***
  Serial.println("Moving to position 0.");
  stepper.moveToPositionInRevolutions(0);
  delay(PAUSE_BETWEEN_MOVES * 1000);
}
