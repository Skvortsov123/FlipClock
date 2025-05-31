#include "ButtonModule.h"
#include "Arduino.h"

#define COLD_DOWN_TIME 100 //miliseconds

ButtonModule::ButtonModule(int pin1, int pin2) {
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  this->pin1 = pin1;
  this->pin2 = pin2;
}

bool ButtonModule::getButtonA() {
  bool rawButton = digitalRead(pin1);
  if (rawButton && timer1 + COLD_DOWN_TIME < millis()){
    timer1 = millis();
    return 1;
  }
  return 0;
}


bool ButtonModule::getButtonB() {
  bool rawButton = digitalRead(pin2);
  if (rawButton && timer2 + COLD_DOWN_TIME < millis()){
    timer2 = millis();
    return 1;
  }
  return 0;
}
