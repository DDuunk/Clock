#include "main.h"

void setup() {
  Serial.begin(115200);
  MPU_INIT();
  RTC_INIT();
  NEOPIXEL_INIT();
}

void loop() {
  MPU_RUN();
  RTC_RUN();
  NEOPIXEL_RUN();
}