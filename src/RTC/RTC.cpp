#include "RTC.h"

void RTC_INIT() {
  while (!Serial);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void RTC_RUN() {
  //Set now as RTC time
  DateTime now = rtc.now();
  //Print RTC time to Serial Monitor

  #ifdef DEBUG_MODE
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  if (now.minute() < 10) { Serial.print("0");}
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  if (now.second() < 10) { Serial.print("0");}
  Serial.print(now.second(), DEC);
  Serial.println("");
  #endif //DEBUG_MODE
  second = now.second(), DEC;
  minute = now.minute(), DEC;
  hour = now.hour(), DEC;
}
 