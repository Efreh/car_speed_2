#include <Arduino.h>
#include <FastLED.h>
#include <GyverHub.h>

#include "car_parameter.h"  // Include a custom header file for car parameters

CRGB leds[NUM_LEDS];  // Define an array to hold the LED colors


// Initialize LED strip configuration
void initLed() {
  FastLED.addLeds<LED_TYPE, BYTE_PIN, COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(param.max_brigh < 255);
}

// Start animation for all LEDs
void startAll_led_animation() {
  for (int i = 0; i < NUM_LEDS; i++) { leds[i] = param.colorArray[i].getHEX(); }  // Set colors for all LEDs based on parameters
  FastLED.show();                                                                 // Update the LED strip with the new colors

  // Gradually increase brightness from 0 to maximum
  for (int i = 0; i < param.max_brigh; i++) {
    FastLED.setBrightness(i);  // Set LED strip brightness
    FastLED.show();            // Update the LED strip with the new brightness
    delay(100);                // Pause for 100 millisecond
  }
}

// Update all LEDs with current colors
void update_AllColor() {
  for (int i = 0; i < NUM_LEDS; i++) { leds[i] = param.colorArray[i].getHEX(); }  // Update colors of all LEDs based on parameters
  FastLED.show();                                                                 // Update the LED strip with the new colors
}
