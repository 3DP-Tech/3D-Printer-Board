# Marlin Firmware for Virtual Printer
## Changed Files
Since the Marlin firmware is updated on a regular basis, this configuration has been fixed for version 2.0.9.2 of the Marlin Firmware. The base Marlin files can be downloaded from [Marlin Firmware 2.0.9.2](https://github.com/MarlinFirmware/Marlin/archive/refs/tags/2.0.9.2.zip).

Unzip the contents of the Marlin firmware into a folder on your hardrive and then copy the configuration files as follows:

* **_Bootscreen.h** => [base]/Marlin-2.0.9.2/Marlin/
* **_Statusscreen.h** => [base]/Marlin-2.0.9.2/Marlin/
* **Configuration_adv.h** => [baset]/Marlin-2.0.9.2/Marlin/
* **Configuration.h** => [base]/Marlin-2.0.9.2/Marlin/

where **[base]** is there folder Marlin-2.0.9.2.zip was unpacked in.

## Change Details

Starting with the default configuration files found in version 2.0.9.2 of the Marlin firmware, applying the changes in this document will result in the configuration necessary to run the virtual printer.
Note the files in Marlin/Virtual Printer/2.0.9.2 already have these configuration changes applied.
### Configuration_adv.h Changes
1.	Uncomment #define FAN_KICKSTART_TIME 100 
2.	Uncomment the line #define FAN_MIN_PWM 50 and change the value to 34
3.	Uncomment the line #define FAN_MAX_PWM 128 and change the value to 255
4.	Uncomment the line #define QUICK_HOME
5.	Uncomment #define LCD_INFO_MENU
6.	Uncomment #define SOUND_MENU_ITEM
7.	Uncomment #define STATUS_MESSAGE_SCROLLING
8.	Uncomment #define SDCARD_READONLY
9.	Uncomment #define LONG_FILENAME_HOST_SUPPORT
10.	Uncomment #define SCROLL_LONG_FILENAMES
11.	Uncomment #define BABYSTEPPING
12. Uncomment #define BABYSTEP_ALWAYS_AVAILABLE
12.	Uncomment #define DOUBLECLICK_FOR_Z_BABYSTEPPING

### Configuration.h Changes

1.	Find #define STRING_CONFIG_H_AUTHOR and change the value to “(Daniel Porrey, 3DP-Tech)"
2. Find #define CUSTOM_MACHINE_NAME and change the value to "V3D Printer"
2.	Uncomment #define SHOW_CUSTOM_BOOTSCREEN
3.	Uncomment #define CUSTOM_STATUS_SCREEN_IMAGE
4.	Find #define BAUDRATE and change the value to 500000
5.	Find #define MOTHERBOARD and change the value to BOARD_CUSTOM
6.	Uncomment #define CUSTOM_MACHINE_NAME and change the name to "Virtual 3DP"
7.	Uncomment #define MACHINE_UUID "00000000-0000-0000-0000-000000000000" and change the value to "3f756d04-a356-4632-ac29-15a5529378b4"
8.	Find #define TEMP_SENSOR_BED and change the value to 1
9.	Find #define BED_MAXTEMP and change the value to 125
10.	Uncomment #define PID_EDIT_MENU
11.	Uncomment #define PID_AUTOTUNE_MENU
12.	Uncomment #define PIDTEMPBED
13.	Find #define PREVENT_COLD_EXTRUSION and comment the line (add // to the beginning)
14.	Find #define PREVENT_LENGTHY_EXTRUDE and comment the line (add // to the beginning)
15.	Find #define DEFAULT_AXIS_STEPS_PER_UNIT and change the values to { 400, 400, 400, 93 }
16.	Find #define DEFAULT_MAX_FEEDRATE and change the values to { 100, 100, 100, 100 }
17.	Find #define DEFAULT_MAX_ACCELERATION and change values to { 500, 500, 500, 500 }
18.	Find #define DEFAULT_ACCELERATION and change the value to 500
19.	Find #define DEFAULT_RETRACT_ACCELERATION and change the value to 500
20.	Find #define DEFAULT_TRAVEL_ACCELERATION and change the value to 500
21.	Find #define JUNCTION_DEVIATION_MM and change the value to 0.08
22. Find #define INVERT_X_DIR and change the value to true
23. Find #define INVERT_Y_DIR and change the value to false
24. Find #define INVERT_E0_DIR and change the value to true
25. Uncomment the line #define SOFT_ENDSTOPS_MENU_ITEM and
25.	Find #define X_BED_SIZE and change the value to 190
26.	Find #define Y_BED_SIZE SIZE and change the value to 190
27.	Find #define Z_MAX_POS and change the value to 240
28.	Find #define HOMING_FEEDRATE_MM_M and change the value to { (30*60), (30*60), (30*60) }
29.	Uncomment #define EEPROM_SETTINGS
30.	Uncomment #define EEPROM_AUTO_INIT
31.	Find #define PREHEAT_1_TEMP_HOTEND and change the value to 207
32.	Find #define PREHEAT_1_TEMP_BED and change the value to 60
33.	Find #define PREHEAT_1_TEMP_CHAMBER and change the value to 0
34.	Find #define PREHEAT_1_FAN_SPEED and change the value 255
35.	Find #define PREHEAT_2_TEMP_BED and change the value to 100
36.	Find #define PREHEAT_2_TEMP_CHAMBER and change the value to 0
37.	Find #define PREHEAT_2_FAN_SPEED and change the value to 255
38.	Uncomment #define SDSUPPORT
39.	Uncomment #define INDIVIDUAL_AXIS_HOMING_MENU
40.	Uncomment #define INDIVIDUAL_AXIS_HOMING_SUBMENU
41.	Uncomment #define SPEAKER
42.	Uncomment #define CR10_STOCKDISPLAY
43.	Uncomment #define FAN_SOFT_PWM

