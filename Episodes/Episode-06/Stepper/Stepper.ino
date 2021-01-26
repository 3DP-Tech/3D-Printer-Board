
#include <SpeedyStepper.h>

// ***
// *** These are the pin assignments for the A4988 board.
// ***
#define MOTOR_STEP_PIN 1
#define MOTOR_DIRECTION_PIN 0
#define MOTOR_EN 14

// ***
// *** Motor steps for 1 full revolution.
// ***
#define STEPS 200

// ***
// *** Defin the microstep configure. This depends on the values of
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
  // *** The rotation has completed. Delay 3 second before repeating the sequence.
  // ***
  delay(3000);
}

void demonstrateRelativeMoves()
{
  // ***
  // *** Rotate the motor in the forward direction one revolution
  // *** and pause 1 second.
  // ***
  Serial.println("Rotating 1 full forward turn.");
  stepper.moveRelativeInSteps(1.0);
  delay(1000);

  // ***
  // *** Rotate the stepper in the opposte direction one
  // *** full revolution and pause 1 second.
  // ***
  Serial.println("Rotatin 1 full reverse turn.");
  stepper.moveRelativeInRevolutions(-1.0);
  delay(1000);

  // ***
  // *** Rotate the motor in the forward direction a half
  // *** revolution and pause 1 second.
  // ***
  Serial.println("Rotating 1/2 forward turn.");
  stepper.moveRelativeInRevolutions(.5);
  delay(1000);
  
  // ***
  // *** Rotate the stepper in the opposte direction a
  // *** half revolution and pause 1 second.
  // ***
  Serial.println("Rotating 1/2 reverse turn.");
  stepper.moveRelativeInRevolutions(-.5);
  delay(1000);
}

void demonstrateAbsoluteMoves()
{
  // ***
  // *** Move the motor to position .500 and pause 1 second.
  // ***
  Serial.println("Moving to position .500.");
  stepper.moveToPositionInRevolutions(.500);
  delay(1000);

  // ***
  // *** Move the motor to .650 and pause 1 second.
  // ***
  Serial.println("Moving to position .650.");
  stepper.moveToPositionInRevolutions(.650);
  delay(1000);

  // ***
  // *** Move the motor to .765 and pause 1 second.
  // ***
  Serial.println("Moving to position .765.");
  stepper.moveToPositionInRevolutions(.765);
  delay(1000);

  // ***
  // *** Move the motor to .085 and pause 1 second.
  // ***
  Serial.println("Moving to position .085.");
  stepper.moveToPositionInRevolutions(.085);
  delay(1000);

  // ***
  // *** Move the motor to .160 and pause 1 second.
  // ***
  Serial.println("Moving to position .160.");
  stepper.moveToPositionInRevolutions(.160);
  delay(1000);

  // ***
  // *** Move the motor to 0 and pause 1 second. The motor
  // *** should be back to the starting point.
  // ***
  Serial.println("Moving to position 0.");
  stepper.moveToPositionInRevolutions(0);
  delay(1000);
}
