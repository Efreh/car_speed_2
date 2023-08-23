#include "car_hub.h"  // Include the header file for car_hub functions and definitions

void setup() {
  // Configure WiFi in Access Point (AP) mode with SSID "SpeedometrLed"
  WiFi.mode(WIFI_AP);
  WiFi.softAP("SpeedometrLed");

  EEPROM.begin(memory.blockSize());  // Begin EEPROM communication
  memory.begin(0, 'b');              // Initialize EEPROM manager with memory block 'b'

  hub_init();  // Initialize GyverHub settings and widgets

  initLed();                 // Initialize LED strip configuration
  update_AllColor();  // Start initial LED animation
  start_anim_selector();
}

void loop() {
  hubTick();      // Handle GyverHub events
  memory.tick();  // Update EEPROM manager (if needed)
}
