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
// We are using the LED that is connected to D7 (PB7, physical pin 8, SCK) pin.
//
#define LED_PIN 7

void setup() {
  //
  // Initialize the LED pin.
  //
  pinMode(LED_PIN, OUTPUT);
  Serial.println("LED pin initialized.");
}

void loop() {
  //
  // Turn the LED on.
  //
  digitalWrite(LED_PIN, HIGH);

  //
  // Wait one second. The clock is running at 1MHz but the code
  // was compiled with a setting of 16MHz so our tmng is off.
  // Use a scalar of 1/16 for all times.
  //
  delay(1000 / 16);

  //
  // Turn the LED off.
  //
  digitalWrite(LED_PIN, LOW);

  //
  // Wait one second. The clock is running at 1MHz but the code
  // was compiled with a setting of 16MHz so our timing is off.
  // Use a scalar of 1/16 for all times.
  //
  delay(1000 / 16);
}
