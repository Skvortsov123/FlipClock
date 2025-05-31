#include "RTClib.h"


void setup() {
  Serial.begin(9600);
  Serial.println("Test");
  delay(100);
  RTC_DS1307 rtc;   //Some issue, makes arduino reboot. Use example timestamp to set time
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println(__DATE__);
  Serial.println(__TIME__);
}

void loop() {
  
}
