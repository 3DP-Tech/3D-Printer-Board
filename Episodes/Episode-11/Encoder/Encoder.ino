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
// The encoder is connected to analog pin D10 (PD2, physical pin 16) and D11 (PD3, pin physical 17).
// The encoder button is connected to pin D16 (PC0, physical pin 22)
//
#define ENCODER_1   11
#define ENCODER_2   10
#define ENCODER_BTN 16

//
// Track the encoder changes.
//
volatile bool _encoderPositionChanged = false;

//
// Track the encoder button.
//
volatile bool _encoderButtonChanged = false;

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
  // Initialize the encoder pins.
  //
  Serial.println("Initializing encoder.");
  pinMode(ENCODER_1, INPUT_PULLUP);
  pinMode(ENCODER_2, INPUT_PULLUP);
  pinMode(ENCODER_BTN, INPUT_PULLUP);

  //
  // Attach interrupts to each of the pins.
  //
  Serial.println("Attaching interrupts.");
  attachInterrupt(digitalPinToInterrupt(ENCODER_1), onEncoderPositionChange, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODER_2), onEncoderPositionChange, RISING);

  //
  // Setup has completed.
  //
  Serial.println("Ready.");
}

void loop() {
  //
  // Check if the encoder button was pushed.
  //
  int value = digitalRead(ENCODER_BTN);
  
  if (value == LOW && !_encoderButtonChanged) {
    _encoderButtonChanged = true;
    Serial.println("Encoder button pushed.");
  }
  else if (value == HIGH && _encoderButtonChanged) {
    _encoderButtonChanged = false;
    Serial.println("Encoder button released.");
  }

  //
  // Check if the encoder position changed.
  //
  if (_encoderPositionChanged) {
    //
    // Read the encoder A value.
    //
    int value1 = digitalRead(ENCODER_1);
    Serial.print("ENCODER_1 = "); Serial.println(value1 == HIGH ? "HIGH" : "LOW");

    //
    // Read the encoder B value.
    //
    int value2 = digitalRead(ENCODER_2);
    Serial.print("ENCODER_2 = "); Serial.println(value1 == HIGH ? "HIGH" : "LOW");

    //
    // Reset the flag.
    //
    _encoderPositionChanged = false;
  }
}

void onEncoderPositionChange() {
  _encoderPositionChanged = true;
}
