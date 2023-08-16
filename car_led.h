#include <Arduino.h>
#include <FastLED.h>
#include <GyverHub.h>
#include "car_parameter.h"

extern GHcolor colorArray[NUM_LEDS];

CRGB leds[NUM_LEDS];

void initLed() {
  FastLED.addLeds<LED_TYPE, BYTE_PIN, COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(MIN_BRIGH < 255);
}

void startAll_led_animation() {
  for (int i = 0; i < NUM_LEDS; i++) { colorArray[i].setRGB(255, 0, 0); }
  for (int i = 0; i < NUM_LEDS; i++) { leds[i] = colorArray[i].getHEX(); }
  FastLED.show();

  //Плавное увеличение яркости
  for (int i = 0; i < 255; i += 5) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(200);
  }
}

void change_AllColor() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = colorArray[i].getHEX();
  }
  FastLED.show();
}
