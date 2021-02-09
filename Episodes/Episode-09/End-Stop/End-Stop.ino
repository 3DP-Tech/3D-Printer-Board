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

//
// The X-Stop switch is connected to D18 (PC2, physical pin 24).
// The Y-Stop switch is connected to D19 (PC3, physical pin 25).
// The Z-Stop switch is connected to D20 (PC4, physical pin 26).
//
#define X_STOP_PIN 18
#define Y_STOP_PIN 19
#define Z_STOP_PIN 20

//
// We are using the built-in LED that is connected to D7 (PB7, physical pin 8, SCK) pin.
//
#define LED_PIN 7

//
// Cache the state of the button.
//
uint16_t _xButtonState = HIGH;
uint16_t _yButtonState = HIGH;
uint16_t _zButtonState = HIGH;

void setup() {
  //
  // Initialize the serial port.
  //
  Serial.begin(500000);

  //
  // Wait for serial port to connect.
  //
  while (!Serial) {}
  Serial.println("Serial port initialized.");

  //
  // Initialize the LED pin.
  //
  pinMode(LED_PIN, OUTPUT);
  Serial.println("LED pin initialized.");

  //
  // Initialize the X End Stop.
  //
  pinMode(X_STOP_PIN, INPUT);
  _xButtonState = digitalRead(X_STOP_PIN);
  Serial.println("X end stop initialized.");

  //
  // Initialize the Y End Stop.
  //
  pinMode(Y_STOP_PIN, INPUT);
  _yButtonState = digitalRead(Y_STOP_PIN);
  Serial.println("Y end stop initialized.");

  //
  // Initialize the Z End Stop.
  //
  pinMode(Z_STOP_PIN, INPUT);
  _zButtonState = digitalRead(Z_STOP_PIN);
  Serial.println("Z end stop initialized.");

  //
  // Display the current state of the end stop switch.
  //
  displayState(_xButtonState, "X");
  displayState(_xButtonState, "Y");
  displayState(_xButtonState, "Z");

  //
  // Setup has completed.
  //
  Serial.println("Ready.");
}

void loop() {
  //
  // Check the X Stop.
  //
  _xButtonState = checkEndStop(X_STOP_PIN, _xButtonState, "X");

  //
  // Check the Y Stop.
  //
  _yButtonState = checkEndStop(Y_STOP_PIN, _yButtonState, "Y");

  //
  // Check the Z Stop.
  //
  _zButtonState = checkEndStop(Z_STOP_PIN, _zButtonState, "Z");
}

int16_t checkEndStop(uint16_t pin, uint16_t previousState, String stopName) {
  uint16_t returnValue = previousState;

  //
  // Read the current state of the pin.
  //
  uint16_t value = digitalRead(pin);

  //
  // Check if the state of the pin has changed.
  //
  if (value != previousState) {
    //
    // Update the LED status.
    //
    displayState(value, stopName);

    //
    // Return the new pin state.
    //
    returnValue = value;
  }

  return returnValue;
}

void displayState(uint16_t state, String stopName)
{
  if (state == HIGH) {
    //
    // Turn the built-in LED on.
    //
    digitalWrite(LED_PIN, LOW);
    Serial.print(stopName); Serial.print(" end stop "); Serial.println(" open");
  }
  else {
    //
    // Turn the built-in LED off.
    //
    digitalWrite(LED_PIN, HIGH);
    Serial.print(stopName); Serial.print(" end stop "); Serial.println(" triggered");
  }
}
