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

#include "MusicNotes.h"

//
// The piezo buzzer is connected to analog pin D7 (PA4, A4, physical pin 36).
//
#define PIEZO_PIN 27

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
  // Setup has completed.
  //
  Serial.println("Ready.");
}

void loop() {
  /* Westminster Chime -> start : 20
      E4, G♯4, F♯4, B3
      E4, F♯4, G♯4, E4
      G♯4, E4, F♯4, B3
      B3, F♯4, G♯4, E4
  */
  
  Serial.println("Playing Westminster Chime.");

  //
  // Play the Westminster Chime.
  //
  tone(PIEZO_PIN, NOTE_E4); delay(800);
  tone(PIEZO_PIN, NOTE_GS4); delay(800);
  tone(PIEZO_PIN, NOTE_FS4); delay(800);
  tone(PIEZO_PIN, NOTE_B3); delay(1600);
  noTone(PIEZO_PIN); delay(200);

  tone(PIEZO_PIN, NOTE_E4); delay(800);
  tone(PIEZO_PIN, NOTE_FS4); delay(800);
  tone(PIEZO_PIN, NOTE_GS4); delay(800);
  tone(PIEZO_PIN, NOTE_E4); delay(1600);
  noTone(PIEZO_PIN); delay(200);

  tone(PIEZO_PIN, NOTE_GS4); delay(800);
  tone(PIEZO_PIN, NOTE_E4); delay(800);
  tone(PIEZO_PIN, NOTE_FS4); delay(800);
  tone(PIEZO_PIN, NOTE_B3); delay(1600);
  noTone(PIEZO_PIN); delay(200);

  tone(PIEZO_PIN, NOTE_B3); delay(800);
  tone(PIEZO_PIN, NOTE_FS4); delay(800);
  tone(PIEZO_PIN, NOTE_GS4); delay(800);
  tone(PIEZO_PIN, NOTE_E4); delay(1600);
  noTone(PIEZO_PIN); delay(200);

  //
  // Wait 5 seconds.
  //
  Serial.println("Playing completed. Waiting 5 seconds...");
  noTone(PIEZO_PIN);
  delay(5000);
}
