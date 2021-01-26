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
// *** Define the pin on which the MOSFET is connected. The layer cooling fan
// *** will be connected to D4 (PB4, physical pin 5).
// ***
#define MOSFET_PIN 4

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
  // *** Start with the fan off. Pause for 2 seconds.
  // ***
  setFan(0, 2);

  // ***
  // *** Setup has completed.
  // ***
  Serial.println("Ready.");
}

void loop()
{
  // ***
  // *** Kick start the fan for 500ms at 100% speed. Sometimes
  // *** low PWM values can't get the fan going.
  // ***
  setFan(1.0, .5);

  // ***
  // *** Loop through fan speeds by increments of 5%
  // *** for 5 seconds at a time.
  // ***
  for (float speed = .35; speed < 1.01; speed += .05)
  {
    setFan(speed, 5);
  }

  // ***
  // *** Turn the fan off.
  // ***
  setFan(0, 10);
}

void setFan(float speed, float duration)
{
  if (speed == 0)
  {
    // ***
    // *** Turn the fan off.
    // ***
    if (duration > 0)
    {
      Serial.print("Turning the fan off for "); Serial.print(duration); Serial.println(" seconds.");
    }
    else
    {
      Serial.println("Turning the fan off.");
    }

    analogWrite(MOSFET_PIN, 0);
  }
  else
  {
    // ***
    // *** Turn the fan off.
    // ***
    Serial.print("Running the fan at "); Serial.print(speed * 100); Serial.print("% for "); Serial.print(duration); Serial.println(" seconds.");
    analogWrite(MOSFET_PIN, (byte)(255 * speed));
  }

  delay(duration * 1000);
}
