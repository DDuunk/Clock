#include "NEOPIXEL.h"

void NEOPIXEL_INIT() {
  strip.begin();
  strip.setBrightness(128);
  strip.show();
}

void NEOPIXEL_RUN() {
  if (MPU.xValue > 0 && MPU.xValue < 90) {
    //colorWipe(strip.Color(255, 0, 0),50);
    mode = 1;
  } else if (MPU.xValue > 90 && MPU.xValue < 180) {
    //colorWipe(strip.Color(0, 255, 0),50); 
    mode = 2;
  } else if (MPU.xValue < 0 && MPU.xValue > -90) {
    //colorWipe(strip.Color(0, 0, 255),50);
    mode = 3;
  } else if (MPU.xValue < -90 && MPU.xValue > -180) {
    //colorWipe(strip.Color(255, 255, 255), 50);
    mode = 4;
  }
  timeCycle(second, minute, hour, mode);
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j = 0; j < 256; j++) {
    for(i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j = 0; j < 256 * 5; j++) {
    for(i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) +j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255- WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void timeCycle(int sec, int min, int h, int mode) {
  switch(mode) {
    case 1: cSec = strip.Color(255, 0, 0); //red
            cMin = strip.Color(0, 255, 0); //green
            cHour = strip.Color(0, 0, 255); //blue
            break;
    case 2: cSec = strip.Color(0, 255, 0); //green
            cMin = strip.Color(0, 0, 255); //blue
            cHour = strip.Color(255, 0, 0); //red
            break;
    case 3: cSec = strip.Color(0, 0, 255); //blue
            cMin = strip.Color(255, 0, 0); //red
            cHour = strip.Color(0, 255, 0); //green
            break;
    case 4: cSec = strip.Color(255, 0, 0); 
            cMin = strip.Color(255, 255, 0); 
            cHour = strip.Color(255, 255, 255);
            break;                       
  }

  if(((sec - 1) / 2.5) < 0 || ((min - 1) / 2.5) < 0 || ((h - 1) * 2) < 0) {
    strip.setPixelColor(23, 0, 0, 0);
    strip.show();
  } else if (((sec - 1) / 2.5) < 1 || ((min - 1) / 2.5) < 1 || ((h - 1) * 2) < 1) {
    strip.setPixelColor(0, 0, 0, 0);
    strip.show();
  } else {
    strip.setPixelColor(((sec - 1) / 2.5), 0, 0, 0);
    strip.setPixelColor(((min -1) / 2.5), 0, 0, 0);
    strip.setPixelColor(((h - 1) * 2), 0, 0, 0);
    strip.show();
  }

  strip.setPixelColor(sec / 2.5, cSec);
  strip.setPixelColor(min / 2.5, cMin);
  strip.setPixelColor(h * 2, cHour);
  strip.show();
}