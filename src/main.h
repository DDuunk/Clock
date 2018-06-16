#ifndef MAIN_H
#define MAIN_H

#define DEBUG_MODE

#include "Arduino.h"
#include <Wire.h>
#include "./MPU/MPU.cpp"
#include "./RTC/RTC.cpp"
#include "./NEOPIXEL/NEOPIXEL.cpp"

void setup();
void loop();

#endif //MAIN_H