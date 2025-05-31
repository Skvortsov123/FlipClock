#include <Wire.h>
#include "DipSwitch.h"
#include "Manager.h"

DipSwitch dip(A0, A1, A2, A3);
Manager manager;

void setup() {
  //Serial.begin(9600);
  Wire.begin(dip.getState());
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void receiveEvent() {
  int newPosition = Wire.read();
  manager.setPosition(newPosition);
  Serial.print("I2CNewPosition: ");
  Serial.println(newPosition);
}

void requestEvent() {
  bool r = manager.ifReady();
  Wire.write(r);
  Serial.print("RequestedState: ");
  Serial.println(r);
}

void loop() {
  manager.tick();
}


