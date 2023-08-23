//Star animations
// Optitron gradually increase brightness from 0 to maximum
void optitron_anim() {
  for (int i = 0; i < param.max_brigh; i++) {
    FastLED.setBrightness(i);  // Set LED strip brightness
    FastLED.show();            // Update the LED strip with the new brightness
    delay(100);                // Pause for 100 millisecond
  }
}
//Fluorescent lamp
void fluorescent_lamp() {
  FastLED.setBrightness(param.max_brigh);
  FastLED.show();
  delay(150);
  FastLED.setBrightness(0);
  FastLED.show();
  delay(150);
  FastLED.setBrightness(param.max_brigh);
  FastLED.show();
  delay(150);
  FastLED.setBrightness(0);
  FastLED.show();
  delay(300);

  FastLED.setBrightness(param.max_brigh);
  FastLED.show();
  delay(150);
  FastLED.setBrightness(0);
  FastLED.show();
  delay(150);
  FastLED.setBrightness(param.max_brigh);
  FastLED.show();
}
//End start animations block