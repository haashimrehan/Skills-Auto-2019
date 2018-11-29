#include "MeOrion.h"
#include <Wire.h>
#include <SoftwareSerial.h>
MeLineFollower lineFinder(Port_2);
void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorState = lineFinder.readSensors();
  switch(sensorState)
    {
      case S1_IN_S2_IN:
        Serial.println("S1 & S2 Black");
        break;
      case S1_IN_S2_OUT:
        Serial.println("S1 Black");
        break;
      case S1_OUT_S2_IN:
        Serial.println("S2 Black");
        break;
      case S1_OUT_S2_OUT:
        Serial.println("N/A");
        break;
      default;
        break;
    }
    delay(200);
}
