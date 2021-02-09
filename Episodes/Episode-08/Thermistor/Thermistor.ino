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
// The Thermistor is connected to analog pin A6 (PA6, physical pin 34).
//
#define THERMISTOR_PIN A6

//
// This code expects an NTC (Negative temperature coefficient) 100K
// thermistor. This means that at 25˚C the resistance of the thermistor
// will be 100KΩ. The resistance will decrease as the temperature increases.
// Temperature calculations are done using the Steinhart–Hart Beta equation.
//

//
// Define the the parameters needed.
//
#define KELVIN     273.15   // This is the temperature in ˚C at 0˚K
#define T0             25   // The nominal temperature of the thermistor.
#define R0         100000   // The thermistor 100KΩ at 25˚C
#define R1           4700   // The voltage divider circuit is using a 4.7Ω resistor
#define B            3950   // Known beta value for the thermistor being used
#define VREF          5.0   // 5.0V in our circuit
#define ADC_RES        10   // The ADC has 10-bit resolution

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
  //
  // Read the voltage across the thermistor. This equation takes the referene
  // voltage and divides it by the number of possible values. The ADC port can
  // return 0 to 1023 which is 1,024 possible value (2 raised the 10th power) where
  // 10 is the bit resolution of the built-in ADC (analog to digital converter).
  //
  // A way to think about this is that with a maximum voltage of 5V, each value
  // read by the ADC is worth 0.0049V or 4.9mV. We simply determine voltage
  // by taking the ADC reading and multiplying it by .0049. In the equation below,
  // (VREF / (pow(2, ADC_RES))) will result in .0049 given the parameters set
  // by the define statements. The code is written this way so that if it is moved
  // to another microcontroller, the paramters can be changed and the equation still
  // works.
  //
  int adc = analogRead(THERMISTOR_PIN);
  Serial.print("ADC = "); Serial.print(adc);
  float v = adc * (VREF / pow(2, ADC_RES));
  Serial.print(", Voltage = "); Serial.print(v, 4); Serial.print("v");

  //
  // Using Ohms Law (V = IR) and Kirchhoff's Law we can calculate the resistance
  // of the thermistor. Our circuit is a basic voltage divider. We know that we have
  // a voltage of VREF (5V in our case) across the two resistors. Kirchhoff's Law
  // states that the voltage across each resistor must ad up to the total (5V). We
  // just read the voltage across the thermistor so we now know that the voltage
  // across our second resistor is VREF - v. Rearrange Ohms Law to solve for R and
  // we get
  //
  // R = V/I
  //
  // Kirchhoff's Law also states, since this is a series circuit, that the current
  // flowing through the two resistors is the same. Since we know the fixed value
  // of the second resistor, we can calculate I (the current).
  //
  // I = V/R where v = VREF - v and R = R1
  //
  // leaving us with the equation
  //
  // I = (VREF - v) / R1
  //
  // The final equation for R is
  //
  // R = v / ((VREF - v) / R1) which can also be stated as R = (v * R1) / (VREF - v)
  //
  float r =  (v * R1) / (VREF - v);
  Serial.print(", Thermistor = "); Serial.print(r / 1000.0, 1); Serial.print("KΩ");

  //
  // Calculate the temperature in Kelvin using a Steinhart–Hart Beta equation. In our
  // case we have a known beta value and so we can use it directly in the equation.
  //
  float tk = 1 / ((1 / (T0 + KELVIN)) + ((log(r / R0)) / B));

  //
  // Convert the temperature to Celsius.
  //
  float tc = tk - KELVIN;

  //
  // Convert the temperature to Fahrenheit.
  //
  float tf = (tc * 1.8) + 32.0;

  //
  // Display the temperature on the serial port.
  //
  Serial.print(", Current temperature: ");
  Serial.print(tk, 1); Serial.print("˚K, ");
  Serial.print(tc, 1); Serial.print("˚C, ");
  Serial.print(tf, 1); Serial.println("˚F");

  //
  // Wait 1 second.
  //
  delay(1000);
}
