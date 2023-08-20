#include <EEManager.h>  // Include the EEManager library for EEPROM management

#define BYTE_PIN D2      // Define the data pin for the LED strip
#define NUM_LEDS 32      // Define the number of LEDs in the strip
#define LED_TYPE WS2812  // Define the type of LEDs (WS2812 in this case)
#define COLOR_ORDER GRB  // Define the color order of the LEDs (Green-Red-Blue)

#define TACHO_STRT_LED 0
#define TACHO_END_LED 11
#define SPEED_STRT_LED 12
#define SPEED_END_LED 25
#define TEMP_STRT_LED 26
#define TEMP_END_LED 28
#define FUEL_STRT_LED 29
#define FUEL_END_LED 31

// Define a structure to hold parameters for the LED strip
struct Param {
  GHcolor colorArray[NUM_LEDS];  // Array to store color values for each LED
  uint8_t max_brigh = 255;       // Default maximum brightness value
};

Param param;  // Create an instance of the Param structure to store parameters

EEManager memory(param);  // Initialize the EEPROM manager with the Param structure