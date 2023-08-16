#include <Arduino.h>

#include "car_hub.h"


void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP("SpeedometrLed");

  hub_init();
  initLed();
  startAll_led_animation();
}
void loop() {
  hubTick();
}
