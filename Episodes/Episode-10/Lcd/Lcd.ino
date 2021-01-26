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
#include <Arduino.h>
#include <U8g2lib.h>

// ***
// *** The LCD data pin is connected to D17 (PC1, physical pin 23).
// ***
#define LCD_DATA 17

// ***
// *** The LCD data pin is connected to D30 (PA1, A1, physical pin 39).
// ***
#define LCD_CLK 30

// ***
// *** The LCD CS pin is connected to D2 (PA3, A3, physical pin 37).
// ***
#define LCD_CS 28

// ***
// *** Create the LCD driver.
// ***
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, LCD_CLK, LCD_DATA, LCD_CS, U8X8_PIN_NONE);

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
  // *** Initialize the LCD library.
  // ***
  u8g2.begin();

  // ***
  // *** Setup has completed.
  // ***
  Serial.println("Ready.");
}

void loop()
{
  for (int i = 0; i <= 70; i++)
  {
    // ***
    // *** Clear the internal memory.
    // ***
    u8g2.clearBuffer();

    // ***
    // *** Choose a font.
    // ***
    u8g2.setFont(u8g2_font_helvR08_te);

    // ***
    // *** Write something to the internal memory.
    // ***
    Serial.print("["); Serial.print(i); Serial.println("] Hello 3D Printing World!");
    u8g2.drawStr(0, i, "Hello 3D Printing World!");

    // ***
    // *** Transfer internal memory to the display.
    // ***
    u8g2.sendBuffer();

    // ***
    // *** Delay 1 second.
    // ***
    delay(50);
  }
}
