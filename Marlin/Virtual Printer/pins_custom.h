#pragma once

//
// Define the board name.
//
#define BOARD_INFO_NAME "Melzi (3DP-Tech)"

// Alter timing for graphical display.
#if HAS_MARLINUI_U8GLIB
  #ifndef BOARD_ST7920_DELAY_1
    #define BOARD_ST7920_DELAY_1 DELAY_NS(125)
  #endif
  #ifndef BOARD_ST7920_DELAY_2
    #define BOARD_ST7920_DELAY_2 DELAY_NS(125)
  #endif
  #ifndef BOARD_ST7920_DELAY_3
    #define BOARD_ST7920_DELAY_3 DELAY_NS(125)
  #endif
#endif

// Including the Melzi board sets up most pins
// as needed, some however, will need to be 
// redefined.
#include "sanguino/pins_MELZI.h"

// ATMEL ATMEGA1284 / SANGUINO / MELZI
//
//                                 +---\/---+
// E-DIR               (D 0) PB0  1|        |40  PA0 (AI 0 / D31)  SDSS
// E-STEP              (D 1) PB1  2|        |39  PA1 (AI 1 / D30)  LCD-CLK
// Z-DIR          INT2 (D 2) PB2  3|        |38  PA2 (AI 2 / D29)  (unused)
// Z-STEP          PWM (D 3) PB3  4|        |37  PA3 (AI 3 / D28)  LCD-CS
// FAN1         SS PWM (D 4) PB4  5|        |36  PA4 (AI 4 / D27)  PIEZO
// MOSI           MOSI (D 5) PB5  6|        |35  PA5 (AI 5 / D26)  Z-EN
// MISO           MISO (D 6) PB6  7|        |34  PA6 (AI 6 / D25)  B-TEMP
// SCK             SCK (D 7) PB7  8|        |33  PA7 (AI 7 / D24)  E-TEMP
//                           RST  9|        |32  AREF
//                           VCC 10|        |31  GND
//                           GND 11|        |30  AVCC
//                         XTAL2 12|        |29  PC7 (D 23)        Y-DIR
//                         XTAL1 13|        |28  PC6 (D 22)        Y-STEP
//  RX            RX0 (D 8)  PD0 14|        |27  PC5 (D 21) TDI    X-DIR
//  TX            TX0 (D 9)  PD1 15|        |26  PC4 (D 20) TDO    Z-STOP
//  ENC-2    INT0 RX1 (D 10) PD2 16|        |25  PC3 (D 19) TMS    Y-STOP
//  ENC-1    INT1 TX1 (D 11) PD3 17|        |24  PC2 (D 18) TCK    X-STOP
//  BED           PWM (D 12) PD4 18|        |23  PC1 (D 17) SDA    LCD-DAT
//  HOT-END       PWM (D 13) PD5 19|        |22  PC0 (D 16) SCL    ENC-BTN
//  XYE-EN        PWM (D 14) PD6 20|        |21  PD7 (D 15) PWM    X-STEP
//                                 +--------+
//

//
// Pin 27 is connected to a piezo.
//
#ifdef BEEPER_PIN
#undef BEEPER_PIN
#endif

#define BEEPER_PIN        27 // Piezo

//
// For the ST9720 LCD display. The values define by the Melzi
// board pins are not the same as this board.
//
#ifdef LCD_PINS_RS
#undef LCD_PINS_RS
#endif

#ifdef LCD_PINS_ENABLE
#undef LCD_PINS_ENABLE
#endif

#ifdef LCD_PINS_D4
#undef LCD_PINS_D4
#endif

#define LCD_PINS_RS       28  // LCD CS
#define LCD_PINS_ENABLE   17  // LCD DAT
#define LCD_PINS_D4       30  // LCD CLK

//
// The encoder buttons also need to be redefined.
//
#ifdef BTN_ENC
#undef BTN_ENC
#endif

#ifdef BTN_EN1
#undef BTN_EN1
#endif

#ifdef BTN_EN2
#undef BTN_EN2
#endif

#define BTN_ENC           16
#define BTN_EN1           11
#define BTN_EN2           10