#include "Manager.h"
#include <Wire.h>

#define UPDATE_TIME 1000 //milliseconds

Manager::Manager() : led(13) {    //Dont try to call rtc too soon, make it in setup

}

void Manager::setup() {
  led.blink(100);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }
}

void Manager::tick() {
  led.tick();
  if (timer1 + UPDATE_TIME < millis()) {
    led.blink(1000);
    timer1 = millis();
    DateTime now = rtc.now();
    //Hours
    int hourStr[2];
    hourStr[0] = now.hour() / 10;
    hourStr[1] = now.hour() % 10;
    //Index 0
    Wire.beginTransmission(3);
    Wire.write(letterIndex('0'+hourStr[0]));
    Wire.endTransmission();
    //Index 1
    Wire.beginTransmission(4);
    Wire.write(letterIndex('0'+hourStr[1]));
    Wire.endTransmission();
    //Minutes
    int minuteStr[2];
    minuteStr[0] = now.minute() / 10;
    minuteStr[1] = now.minute() % 10;
    //Index 0
    Wire.beginTransmission(5);
    Wire.write(letterIndex('0'+minuteStr[0]));
    Wire.endTransmission();
    //Index 1
    Wire.beginTransmission(6);
    Wire.write(letterIndex('0'+minuteStr[1]));
    Wire.endTransmission();
  }
}

int Manager::letterIndex(char target) {
  for (int i = 0; i < sizeof(wheelCommon); i++) {
    if (wheelCommon[i] == target) {
      return i;
    }
  }
  return 40;
}