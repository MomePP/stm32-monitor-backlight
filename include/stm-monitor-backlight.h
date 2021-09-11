#ifndef __STM_MONITOR_BACKLIGHT_H__
#define __STM_MONITOR_BACKLIGHT_H__

#include <Arduino.h>
#include <FastLED.h>
FASTLED_USING_NAMESPACE

#define LED_TYPE                        WS2812B
// #define NEOPIXEL_DATA_PIN				17			//? actual pin number for PA7
#define NEOPIXEL_DATA_PIN				PA7			//? actual pin number for PA7
#define COLOR_ORDER                     GRB
#define NEOPIXEL_NUMPIXELS      		40

#define NEOPIXEL_GLOBAL_BRIGHTNESS      120

#define NEOPIXEL_FRAMES_PER_SECOND  120

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

#endif