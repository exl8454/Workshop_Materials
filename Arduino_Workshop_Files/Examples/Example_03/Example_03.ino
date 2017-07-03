/*
 * Arduino Workshop
 * Example_03.ino
 * This example shows how to incorporate data from IMU with other devices,
 * such as computer
 */

#include <LSM303_L3GD20H.h>

void setup()
{
  Serial.begin(115200);
  startSensor();
}

void loop()
{
  readSensor();
  Serial.print(m[0]); Serial.print(" "); Serial.print(m[1]); Serial.print(" "); Serial.print(m[2]); Serial.println();
  delay(1000);
}

