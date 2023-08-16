#include <Arduino.h>
#define GH_NO_MQTT
#include <GyverHub.h>

#include "car_led.h"
#include "car_parameter.h"

GyverHub hub("MyDevices", "SpeedometrLed", "");

GHcolor colorArray[NUM_LEDS];
GHbutton updateBtn;

void build() {
  //Кнопка выбора цвета в палитре
  hub.BeginWidgets();
  hub.WidgetSize(30);
  for (int i = 0; i < NUM_LEDS; i++) {
    hub.Color(&colorArray[i], String(F("led ")) + i);
  }

  hub.BeginWidgets();
  hub.WidgetSize(50);
  hub.Button(&updateBtn, F("Update color"), GH_RED);

  hub.EndWidgets();
}

void hub_init() {
  hub.onBuild(build);  // подключаем билдер
  hub.begin();         // запускаем систему
}

void hubTick() {
  hub.tick();
  if (updateBtn) { change_AllColor(); }
}