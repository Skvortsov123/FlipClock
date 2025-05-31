#include "RTClib.h"
#include "Led.h"

#ifndef MANAGER_H
#define MANAGER_H

class Manager {
  public:
    Manager();
    void setup();
    void tick();
  private:
    RTC_DS3231 rtc; //Should be RTC_DS3231, alt RTC_DS1307
    Led led;
    unsigned long timer1 = 0;
    char wheelCommon[40] = {'1','2','3','4','5','6','7','8','9','0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','-','+','?','!'};
    int letterIndex(char target);
};

#endif