#include <Arduino.h>
#define GH_NO_MQTT
#include <GyverHub.h>

#include "car_led.h"

GyverHub hub("MyDevices", "SpeedometrLed", "");

GHbutton updateBtn;
GHbutton saveBtn;

void build() {
  
  //Кнопка выбора цвета в палитре
  hub.BeginWidgets();
  hub.WidgetSize(30);
  for (int i = 0; i < NUM_LEDS; i++) {
    hub.Color(&param.colorArray[i], String(F("led ")) + i);
  }

  hub.BeginWidgets();
  hub.WidgetSize(50);
  hub.Slider(&param.max_brigh, GH_UINT8, F("Brightness"), 0, 255);
  hub.Button(&updateBtn, F("Update color"), GH_RED);
  hub.Button(&saveBtn, F("Save color"), GH_RED);

  hub.EndWidgets();
}

void hub_init() {
  hub.onBuild(build);  // подключаем билдер
  hub.begin();         // запускаем систему
}

void hubTick() {
  hub.tick();
  if (updateBtn) {
    update_AllColor();
  }
  if (saveBtn) {
    memory.update();
  }
}