#pragma once

//
// Define the board name
//
#define BOARD_INFO_NAME "Melzi (3DP-Tech)"

//
// Alter timing for graphical display
//
#ifndef BOARD_ST7920_DELAY_1
	#define BOARD_ST7920_DELAY_1 DELAY_NS(125)
#endif
#ifndef BOARD_ST7920_DELAY_2
	#define BOARD_ST7920_DELAY_2 DELAY_NS(125)
#endif
#ifndef BOARD_ST7920_DELAY_3
	#define BOARD_ST7920_DELAY_3 DELAY_NS(125)
#endif

//
// This board is based off of the Melzi board.
//
#include "sanguino/pins_MELZI.h"

// ATMEL ATMEGA1284 / SANGUINO / MELZI
//
//                                +---\/---+
// E-DIR               (D0) PB0  1|         |40  PA0 (A0 / D31)  SDSS
// E-STEP              (D1) PB1  2|         |39  PA1 (A1 / D30)  LCD-CLK
// Z-DIR          INT2 (D2) PB2  3|         |38  PA2 (A2 / D29)  (unused)
// Z-STEP          PWM (D3) PB3  4|         |37  PA3 (A3 / D28)  LCD-CS
// FAN1         SS PWM (D4) PB4  5|         |36  PA4 (A4 / D27)  PIEZO
// MOSI           MOSI (D5) PB5  6|         |35  PA5 (A5 / D26)  Z-EN
// MISO           MISO (D6) PB6  7|         |34  PA6 (A6 / D25)  B-TEMP
// SCK             SCK (D7) PB7  8|         |33  PA7 (A7 / D24)  E-TEMP
//                          RST  9|         |32  AREF
//                          VCC 10|         |31  GND
//                          GND 11|         |30  AVCC
//                        XTAL2 12|         |29  PC7 (D23)        Y-DIR
//                        XTAL1 13|         |28  PC6 (D22)        Y-STEP
//  RX            RX0 (D8)  PD0 14|         |27  PC5 (D21) TDI    X-DIR
//  TX            TX0 (D9)  PD1 15|         |26  PC4 (D20) TDO    Z-STOP
//  ENC-2    INT0 RX1 (D10) PD2 16|         |25  PC3 (D19) TMS    Y-STOP
//  ENC-1    INT1 TX1 (D11) PD3 17|         |24  PC2 (D18) TCK    X-STOP
//  BED           PWM (D12) PD4 18|         |23  PC1 (D17) SDA    LCD-DAT
//  HOT-END       PWM (D13) PD5 19|         |22  PC0 (D16) SCL    ENC-BTN
//  XYE-EN        PWM (D14) PD6 20|         |21  PD7 (D15) PWM    X-STEP
//                                +--------+
//

//
// Pin 27 is connected to a piezo.
//
#ifdef BEEPER_PIN
#undef BEEPER_PIN
#endif
#define BEEPER_PIN        27 // Piezo

//
// For the ST9720 LCD display. The values defined by the Melzi
// board pins are not the same as this board.
//
#ifdef LCD_PINS_RS
	#undef LCD_PINS_RS
#endif
#define LCD_PINS_RS       28  // LCD CS

#ifdef LCD_PINS_ENABLE
	#undef LCD_PINS_ENABLE
#endif
#define LCD_PINS_ENABLE   17  // LCD DAT

#ifdef LCD_PINS_D4
	#undef LCD_PINS_D4
#endif
#define LCD_PINS_D4       30  // LCD CLK

//
// The fan pin needs to be set
//
#ifdef FAN_PIN
	#undef FAN_PIN
#endif
#define FAN_PIN       	   4

//
// The encoder buttons also need to be redefined.
//
#ifdef BTN_ENC
	#undef BTN_ENC
#endif
#define BTN_ENC           16

#ifdef BTN_EN1
	#undef BTN_EN1
#endif
#define BTN_EN1           11

#ifdef BTN_EN2
	#undef BTN_EN2
#endif
#define BTN_EN2           10

//
// Sanity checks.
//
#if !defined(FAN_PIN) && IS_MELZI
	#error "Custom board definition failed!"
#endif

#if E0_DIR_PIN != 0
	#error "E0_DIR_PIN is assigned to the wrong pin!"
#endif

#if E0_STEP_PIN != 1
	#error "E0_STEP_PIN is assigned to the wrong pin!"
#endif

#if Z_DIR_PIN != 2
	#error "Z_DIR_PIN is assigned to the wrong pin!"
#endif

#if Z_STEP_PIN != 3
	#error "Z_STEP_PIN is assigned to the wrong pin!"
#endif

#if FAN_PIN != 4
	#error "The fan is assigned to the wrong pin!"
#endif

// MOSI 5
// MISO 6
// SCK  7
// RX0  8
// TX0  9

#if BTN_EN2 != 10
	#error "BTN_EN2 is assigned to the wrong pin!"
#endif

#if BTN_EN1 != 11
	#error "BTN_EN1 is assigned to the wrong pin!"
#endif

#if HEATER_BED_PIN != 12
	#error "HEATER_BED_PIN is assigned to the wrong pin!"
#endif

#if HEATER_0_PIN != 13
	#error "HEATER_0_PIN is assigned to the wrong pin!"
#endif

#if X_ENABLE_PIN != 14
	#error "X_ENABLE_PIN is assigned to the wrong pin!"
#endif

#if Y_ENABLE_PIN != 14
	#error "Y_ENABLE_PIN is assigned to the wrong pin!"
#endif

#if E0_ENABLE_PIN != 14
	#error "E0_ENABLE_PIN is assigned to the wrong pin!"
#endif

#if X_STEP_PIN != 15
	#error "X_STEP_PIN is assigned to the wrong pin!"
#endif

#if BTN_ENC != 16
	#error "BTN_ENC is assigned to the wrong pin!"
#endif

#if LCD_PINS_ENABLE != 17
	#error "LCD_PINS_ENABLE is assigned to the wrong pin!"
#endif

#if X_STOP_PIN != 18
	#error "X_STOP_PIN is assigned to the wrong pin!"
#endif

#if Y_STOP_PIN != 19
	#error "Y_STOP_PIN is assigned to the wrong pin!"
#endif

#if Z_STOP_PIN != 20
	#error "Z_STOP_PIN is assigned to the wrong pin!"
#endif

#if X_DIR_PIN != 21
	#error "X_DIR_PIN is assigned to the wrong pin!"
#endif

#if Y_STEP_PIN != 22
	#error "Y_STEP_PIN is assigned to the wrong pin!"
#endif

#if Y_DIR_PIN != 23
	#error "Y_DIR_PIN is assigned to the wrong pin!"
#endif

#if TEMP_0_PIN != 7 // Analog pin; D24
	#error "TEMP_0_PIN is assigned to the wrong pin!"
#endif

#if TEMP_BED_PIN != 6 // Analog pin; D25
	#error "TEMP_BED_PIN is assigned to the wrong pin!"
#endif

#if Z_ENABLE_PIN != 26
	#error "Z_ENABLE_PIN is assigned to the wrong pin!"
#endif

#if BEEPER_PIN != 27
	#error "BEEPER_PIN is assigned to the wrong pin!"
#endif

#if LCD_PINS_RS != 28
	#error "LCD_PINS_RS is assigned to the wrong pin!"
#endif

// Unused 29

#if LCD_PINS_D4 != 30
	#error "LCD_PINS_D4 is assigned to the wrong pin!"
#endif