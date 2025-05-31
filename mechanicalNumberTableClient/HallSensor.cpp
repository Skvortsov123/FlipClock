#include "HallSensor.h"
#include "Arduino.h"

HallSensor::HallSensor(int pin) {
  pinMode(pin, INPUT_PULLUP);
  this->_pin = pin;
}

void HallSensor::onTick() {
  _previousState = _newState;
  _newState = state();
}

bool HallSensor::state() {
  return digitalRead(_pin);
}

bool HallSensor::triggered() {
  if (_newState == 1 && _previousState == 0) {
    return 1;
  }
  return 0; //Why it does not works with out return 0???
}

bool HallSensor::unTriggered() {
  if (_newState == 0 && _previousState == 1) {
    return 1;
  }
  return 0;
}