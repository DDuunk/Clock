#ifndef RTC_H
#define RTC_H

//#define DEBUG_MODE

#include "Arduino.h"
#include <Wire.h>
#include "RTClib.h"

#define RTC_addr 0x68
RTC_DS1307 rtc;

int second;
int minute;
int hour;

void RTC_INIT();
void RTC_RUN();

#endif //RTC_H