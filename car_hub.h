#define GH_NO_MQTT     // Define to exclude MQTT functionality
#include <GyverHub.h>  // Include the GyverHub library for creating widgets
#include "car_led.h"  // Include the header file for LED parameters

GyverHub hub("MyDevices", "SpeedometrLed", "");  // Create a GyverHub instance with specified credentials

GHbutton updateBtn;  // Declare a button widget for updating colors
GHbutton saveBtn;    // Declare a button widget for saving colors

// Define the build function to create widgets
void build() {
  hub.BeginWidgets();  // Start building widgets
  hub.WidgetSize(30);  // Set the widget size

  // Create color picker widgets for each LED
  for (int i = 0; i < NUM_LEDS; i++) {
    hub.Color(&param.colorArray[i], String(F("led ")) + i);  // Create a color picker widget for LED i
  }

  hub.BeginWidgets();  // Start a new row of widgets
  hub.WidgetSize(50);  // Set the widget size

  // Create a slider widget for adjusting maximum brightness
  hub.Slider(&param.max_brigh, GH_UINT8, F("Brightness"), 0, 255);

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
}
