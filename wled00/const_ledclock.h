#include "inttypes.h"
#include "Arduino.h"

#ifndef WLED_CONST_LEDCLOCK_H
#define WLED_CONST_LEDCLOCK_H

#define MDNS_PREFIX "ledclock"
#define MQTT_DEVICE_TOPIC "ledclock"
#define MQTT_CLIENT_ID "LEDCLOCK"

#define BUZZER_PIN 12
#define ADC_MAX_VALUE 4095
#define ADC_MAX_VOLTAGE 3.3
#define BRIGHTNESS_SAMPLES 1024
#define BRIGHTNESS_THRESHOLD 5
#define BRIGHTNESS_PIN 34

#define STOPWATCH_MAX_LAP_TIMES 100

#define BEEP_SILENT 255

// How to configure the display?
//
// Think of your clock display as 2D matrix of pixels rather than a 7 segment display.
//
// Some pixels of this 2D matrix are missing, others are present. To get the layout
// where the pixels are missing or present, first decide on how many LEDs you want per segment.
//
// For example,  if you have only one LED per segment, the layout is the following:
//
//  -#--#---#--#-
//  #-##-###-##-#
//  -#--#---#--#-
//  #-##-###-##-#
//  -#--#---#--#-
//
// Where the symbol '-' represents a missing pixel and symbol '#' represents a pixel that presents.
// Note the two 'separator' pixels in the middle 'horizontal' column.
//
// If you have 2 LEDs per segment,  the layout is the following:
//
// -##--##---##--##-
// #--##--#-#--##--#
// #--##--###--##--#
// -##--##---##--##-
// #--##--###--##--#
// #--##--#-#--##--#
// -##--##---##--##-
//
// Similarly,  on case of 3 LEDs per segment:
//
// -###--###---###--###-
// #---##---#-#---##---#
// #---##---###---##---#
// #---##---#-#---##---#
// -###--###---###--###-
// #---##---#-#---##---#
// #---##---###---##---#
// #---##---#-#---##---#
// -###--###---###--###-
//
// Next you need to replace all the '-' symbols with -1 and all the '#' symbols with LED indices. Which index
// you write in place of a particular '#' symbol depends on the physical layout of your LED strip.
//
// In the example below there are 2 LEDs per segment, and the LED strip begins with the bottommost segment of
// the first number then continues with the leftmost segments from the bottom to the top. I added extra spaces
// between the numbers and the separator column just for better clarity.

#define LC_LEDS_PER_SEGM 9 // LEDs per segment

#define LC_LEDMAP \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,       -1,  63,  64,  65,  66,  67,  68,  69,  70,  71,  -1,      -1,      -1, 126, 127,  128,  129, 130, 131, 132, 133, 134,  -1,    -1, 189, 190, 191, 192, 193, 194, 195, 196, 197,  -1, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  17,       62,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  72,      -1,     125,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 135,   188,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 198, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  16,       61,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  73,     207,     124,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 136,   187,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 199, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  15,       60,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  74,     208,     123,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 137,   186,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 200, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  14,       59,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  75,     209,     122,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 138,   185,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 201, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  13,       58,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  76,     210,     121,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 139,   184,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 202, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  12,       57,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  77,     211,     120,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 140,   183,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 203, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  11,       56,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  78,     212,     119,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 141,   182,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 204, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  10,       55,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  79,      -1,     118,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 142,   181,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 205, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   9,       54,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  80,      -1,     117,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 143,   180,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 206, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,       -1,  53,  52,  51,  50,  49,  48,  47,  46,  45,  -1,      -1,      -1, 116, 115, 114, 113, 112, 111, 110, 109, 108,  -1,    -1, 179, 178, 177, 176, 175, 174, 173, 172, 171,  -1, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   8,       18,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  44,      -1,      81,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 107,   144,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 170, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   7,       19,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  43,      -1,      82,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 106,   145,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 169, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   6,       20,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  42,     213,      83,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 105,   146,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 168, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   5,       21,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  41,     214,      84,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 104,   147,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 167, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   4,       22,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  40,     215,      85,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 103,   148,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 166, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   3,       23,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  39,     216,      86,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 102,   149,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 165, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   2,       24,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  38,     217,      87,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 101,   150,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 164, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   1,       25,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  37,     218,      88,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 100,   151,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 163, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,       26,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  36,      -1,      89,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  99,   152,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 162, \
   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,       -1,  27,  28,  29,  30,  31,  32,  33,  34,  35,  -1,      -1,      -1,  90,  91,  92,  93,  94,  95,  96,  97,  98,  -1,    -1, 153, 154, 155, 156, 157, 158, 159, 160, 161,  -1, 

// Next configure the separator LEDs by first defining how many of them you have:
#define LC_SEP_LEDS 12

// Then write their row indices separated by commas below (notice the separator LEDs #28 and #29 having row indices 2 and 4 in the above LED map):
// #define LC_SEP_LED_ROWS 1, 2
#define LC_SEP_LED_ROWS 2,3,4,5,6,7,13,14,15,16,17,18

// Finally, don't forget to change the total number of LEDs (DEFAULT_LED_COUNT) in `platformio_override.ini`,
// set it to the total size of the LED matrix you have. This number is calculated below and a compiler warning
// is emitted if it does not match with DEFAULT_LED_COUNT.

#define LC_COLS     (((LC_LEDS_PER_SEGM + 2) * 4) + 1)
#define LC_ROWS      ((LC_LEDS_PER_SEGM * 2) + 3)
#define LC_TOTAL_LEDS (LC_COLS * LC_ROWS) // DEFAULT_LED_COUNT should be set to this value

#if !defined(DEFAULT_LED_COUNT) || DEFAULT_LED_COUNT != LC_TOTAL_LEDS
#define LC_XSTR(x) LC_STR(x)
#define LC_STR(x) #x
#pragma message "Macro DEFAULT_LED_COUNT is not defined or is not equal to the calculated number of total LEDs: " LC_XSTR(LC_TOTAL_LEDS)
#endif

// Your display still does not work properly? Verify all the steps above, and if everything looks right, follow these steps:
//   1. navigate your browser http://wled-ip/edit
//   2. right click on /ledmap.json
//   3. choose 'Delete'
//   4. reboot WLED
// The file ledmap.json should now be regenerated with the correct settings and your display should now work properly.


#define LC_PHYSICAL_LEDS (LC_SEP_LEDS + 4 * 7 * LC_LEDS_PER_SEGM)

#define LC_R(c) (byte((c) >> 16))
#define LC_G(c) (byte((c) >> 8))
#define LC_B(c) (byte(c))
#define LC_W(c) (byte((c) >> 24))

class LedClockSettingsKeys {
public:
    static const char *root;

    class Brightness {
    public:
        static const char *autom, *min, *max;
    };

    class Display {
    public:
        static const char *separatorMode, *hideZero;
    };

    class Beeps {
    public:
        static const char *mute, *startup, *wifi;

        class Clock {
        public:
            static const char *minute, *hour;
        };

        class Timer {
        public:
            static const char *set, *start, *pause, *resume, *reset, *increase, *hour, *minute, *second, *timeout;
        };

        class Stopwatch {
        public:
            static const char *start, *pause, *resume, *reset, *second, *minute, *hour, *lapTime;
        };
    };
};

class LedClockStateKeys {
public:
    static const char *root, *command, *mode, *beep, *blendingMode, *canvasColor;

    class Timer {
    public:
        static const char *root, *running, *paused, *left, *value;
    };

    class Stopwatch{
    public:
        static const char *root, *running, *paused, *elapsed, *lapTimes, *lapTimeNr, *lastLapTime;
    };
};

class LedClockSettings {

public:
    enum SeparatorMode {
        ON, OFF, BLINK
    };

    virtual ~LedClockSettings() {}
    bool autoBrightness = true;
    uint8_t minBrightness = 50; // must NOT be lower than 1
    uint8_t maxBrightness = 255;
    SeparatorMode separatorMode = SeparatorMode::BLINK;
    bool hideZero = true;

    bool muteBeeps = false;

    uint8_t beepStartup, beepWiFi;
    uint8_t clockBeepMinute, clockBeepHour;
    uint8_t timerBeepSet, timerBeepStart, timerBeepPause, timerBeepResume, timerBeepReset, timerBeepIncrease, timerBeepHour, timerBeepMinute, timerBeepSecond, timerBeepTimeout;
    uint8_t stopwatchBeepStart, stopwatchBeepPause, stopwatchBeepResume, stopwatchBeepReset, stopwatchBeepSecond, stopwatchBeepMinute, stopwatchBeepHour, stopwatchBeepLapTime;

    virtual void applySettings() = 0;

    static uint8_t constrainBeep(uint8_t beep);
};

const char JSON_ledclock_beeps[] PROGMEM = R"=====([
"1x 330Hz (short)",
"2x 330Hz (short)",
"3x 330Hz (short)",
"1x 440Hz (short)",
"2x 440Hz (short)",
"3x 440Hz (short)",
"1x 880Hz (short)",
"2x 880Hz (short)",
"3x 880Hz (short)",
"1x 330Hz (medium)",
"2x 330Hz (medium)",
"3x 330Hz (medium)",
"1x 440Hz (medium)",
"2x 440Hz (medium)",
"3x 440Hz (medium)",
"1x 880Hz (medium)",
"2x 880Hz (medium)",
"3x 880Hz (medium)",
"1x 330Hz (long)",
"2x 330Hz (long)",
"3x 330Hz (long)",
"1x 440Hz (long)",
"2x 440Hz (long)",
"3x 440Hz (long)",
"1x 880Hz (long)",
"2x 880Hz (long)",
"3x 880Hz (long)",
"440/880Hz (short)",
"880/440Hz (short)",
"440/880Hz (medium)",
"880/440Hz (medium)",
"440/880Hz (long)",
"880/440Hz (long)",
"Turn Up",
"Turn Down",
"Flip Up",
"Flip Down",
"Tadaaa"
])=====";

// custom effects

#define FX_MODE_LC_2SOFIX     187
#define FX_MODE_LC_VORTEX     188
#define FX_MODE_LC_CONCENTRIC 189

// forward declarations

void ledClockTimeUpdated();

#endif