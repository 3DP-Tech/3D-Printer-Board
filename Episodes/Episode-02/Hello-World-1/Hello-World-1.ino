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

// ***
// *** We are using the LED that is connected to D7 (PB7, physical pin 8, SCK) pin. 
// ***
#define LED_PIN 7

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
  // *** Initialize the LED pin.
  // ***
  pinMode(LED_PIN, OUTPUT);
  Serial.println("LED pin initialized.");

  // ***
  // *** Setup has completed.
  // ***
  Serial.println("Ready.");
}

void loop()
{
  // ***
  // *** Turn the LED on and wait one second.
  // ***
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED on.");
  delay(1000);

  // ***
  // *** Turn the LED off and wait one second.
  // ***
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED off.");
  delay(1000);
}
