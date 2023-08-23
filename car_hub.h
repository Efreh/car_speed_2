#define GH_NO_MQTT     // Define to exclude MQTT functionality
#include <GyverHub.h>  // Include the GyverHub library for creating widgets
#include "car_led.h"   // Include the header file for LED parameters

GyverHub hub("MyDevices", "SpeedometrLed", "");  // Create a GyverHub instance with specified credentials

GHbutton updateBtn;  // Declare a button widget for updating colors
GHbutton saveBtn;    // Declare a button widget for saving colors
GHbutton previewAnimBtn;

// Define the build function to create widgets
void build() {
  hub.BeginWidgets();  // Start building widgets
  hub.WidgetSize(30);  // Set the widget size

  // Leds colors button
  hub.Title(F("Speedometr leds"));
  for (int i = TACHO_STRT_LED; i <= TACHO_END_LED; i++) {
    hub.Color(&param.colorArray[i], String(F("led ")) + i);
  }
  hub.Title(F("Tacho leds"));
  for (int i = SPEED_STRT_LED; i <= SPEED_END_LED; i++) {
    hub.Color(&param.colorArray[i], String(F("led ")) + i);
  }
  hub.Title(F("Temp leds"));
  for (int i = TEMP_STRT_LED; i <= TEMP_END_LED; i++) {
    hub.Color(&param.colorArray[i], String(F("led ")) + i);
  }
  hub.Title(F("Fuel leds"));
  for (int i = FUEL_STRT_LED; i <= FUEL_END_LED; i++) {
    hub.Color(&param.colorArray[i], String(F("led ")) + i);
  }

  hub.Title(F("Settings"));
  hub.WidgetSize(70);
  hub.Select(&param.start_animation_mode, F("Optitron,Fluorescent lamp"), F("Start animations"));
  hub.WidgetSize(30);
  hub.Button(&previewAnimBtn, F("Preview"), GH_GREEN);


  hub.WidgetSize(100);  // Set the widget size
  // Create a slider widget for adjusting maximum brightness
  hub.Slider(&param.max_brigh, GH_UINT8, F("Brightness"), 0, 255);

  hub.WidgetSize(50);  // Set the widget size
  // Create buttons for updating and saving color changes
  hub.Button(&updateBtn, F("Update color"), GH_GREEN);
  hub.Button(&saveBtn, F("Save color"), GH_RED);
}

// Initialize GyverHub and set up the build function
void hub_init() {
  hub.onBuild(build);  // Set the build function for creating widgets
  hub.begin();         // Initialize GyverHub
}

// Function to be called repeatedly to handle GyverHub events
void hubTick() {
  hub.tick();  // Process GyverHub events
  if (updateBtn) {
    update_AllColor();  // If the update button is pressed, update LED colors
  }
  if (saveBtn) {
    memory.update();  // If the save button is pressed, update EEPROM with new color data
  }
  if (previewAnimBtn) {
    FastLED.setBrightness(0);
    start_anim_selector();
  }
}