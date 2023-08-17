#include <Arduino.h>
#include <EEManager.h>

#define BYTE_PIN D2
#define NUM_LEDS 32
#define MIN_BRIGH 0
#define MAX_BRIGH 255
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

struct Param {
  GHcolor colorArray[NUM_LEDS];
  uint8_t max_brigh = 255;
};

Param param;

EEManager memory(param);