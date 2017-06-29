/*
 * Arduino Workshop
 * Works_018_a
 * I2C Communication (2)
 * 
 * Previously, we had various definitions around sketch.
 * This sketch shows how to 'eliminate' them.
 */

#include <Wire.h>
/* We make our own library in Arduino! */
#include <Works_Accel.h>

Works_Accel accel;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting up...");
  accel.begin();
  Serial.println("Started");
}

void loop()
{
  accel.read();
  Serial.print("x: "); Serial.print(accel.vector.xg);
  Serial.print(" y: "); Serial.print(accel.vector.yg);
  Serial.print(" z: "); Serial.println(accel.vector.zg);

  Serial.println();
  delay(100);
}

