#include <Arduino.h>

#include "car_hub.h"


void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP("SpeedometrLed");

  EEPROM.begin(memory.blockSize());
  memory.begin(1000, 'b');

  hub_init();

  initLed();
  startAll_led_animation();
}
void loop() {
  hubTick();
  memory.tick();
}
