#include <Arduino.h>
#include <FastLED.h>
#include <GyverHub.h>

#include "car_parameter.h"  // Include a custom header file for car parameters
#include "car_led_anim.h"

CRGB leds[NUM_LEDS];  // Define an array to hold the LED colors

// Update all LEDs with current colors
void update_AllColor() {
  for (int i = 0; i < NUM_LEDS; i++) { leds[i] = param.colorArray[i].getHEX(); }  // Update colors of all LEDs based on parameters
  FastLED.show();                                                                 // Update the LED strip with the new colors
}

void start_anim_selector() {
  switch (param.start_animation_mode) {
    case 0:
      optitron_anim();
      break;
    case 1:
      fluorescent_lamp();
      break;
  }
}


// Initialize LED strip configuration
void initLed() {
  FastLED.addLeds<LED_TYPE, BYTE_PIN, COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(param.max_brigh < 255);
}
