#include <Arduino.h>

// Масив з номерами GPIO для світлодіодів (підключені через резистори до GND)
const uint8_t ledPins[] = {4, 5, 6, 7};
const uint8_t numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (uint8_t i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  // Тест: всі LED вмикаються на 1 секунду при старті
  for (uint8_t i = 0; i < numLeds; i++) digitalWrite(ledPins[i], HIGH);
  delay(1000);
  for (uint8_t i = 0; i < numLeds; i++) digitalWrite(ledPins[i], LOW);
  delay(500);
}



