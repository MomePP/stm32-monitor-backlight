#include <Arduino.h>

#include "stm-monitor-backlight.h"

CRGB leds[NEOPIXEL_NUMPIXELS];
uint8 _ledsBrightness = NEOPIXEL_GLOBAL_BRIGHTNESS;

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0;                  // rotating "base color" used by many of the patterns

void rainbow()
{
    // FastLED's built-in rainbow generator
    fill_rainbow(leds, NEOPIXEL_NUMPIXELS, gHue, 7);
}

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
// SimplePatternList gPatterns = {rainbow};

void nextPattern()
{
    // add one to the current pattern number, and wrap around at the end
    gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);
}

void setup()
{
    delay(3000);

    //? Fast LED initialize
    FastLED.addLeds<LED_TYPE, NEOPIXEL_DATA_PIN, COLOR_ORDER>(leds, NEOPIXEL_NUMPIXELS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(NEOPIXEL_GLOBAL_BRIGHTNESS);
    FastLED.show();
}

void loop()
{
    // Call the current pattern function once, updating the 'leds' array
    gPatterns[gCurrentPatternNumber]();

    // send the 'leds' array out to the actual LED strip
    FastLED.show();
    // insert a delay to keep the framerate modest
    FastLED.delay(1000 / NEOPIXEL_FRAMES_PER_SECOND);

    // do some periodic updates
    EVERY_N_MILLISECONDS(20) { gHue++; }   // slowly cycle the "base color" through the rainbow
    EVERY_N_SECONDS(10) { nextPattern(); } // change patterns periodically
}

