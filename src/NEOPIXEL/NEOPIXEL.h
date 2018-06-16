#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#define DEBUG_MODE

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRBW + NEO_KHZ800);
uint8_t  offset = 0; // Position of spinny eyes
int mode;
uint32_t cSec, cMin, cHour;

void NEOPIXEL_INIT();
void NEOPIXEL_RUN();
void colorWipe(uint32_t c, uint8_t wait);
void rainbow(uint8_t wait);
void rainbowCycle(uint8_t wait);
uint32_t Wheel(byte WheelPos);
void timeCycle(int second, int minute, int hour, int mode);

#endif //NEOPIXEL_H