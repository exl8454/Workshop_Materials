/*
 * Arduino Workshop
 * Works_017_c
 * I2C Communication (2)
 * 
 * Here we will be making our own package for sensor
 */

#include <LIS3DH.h>

float g[3];
long raw[3];

void setup()
{
  Serial.begin(115200);
  startSensor();
  delay(1000);
}

void loop()
{
  readSensor(g, raw);
  Serial.print(g[0]); Serial.print(" ");
  Serial.print(g[1]); Serial.print(" ");
  Serial.print(g[2]); Serial.println(" ");
  delay(100);
}

