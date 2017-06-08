// Arduino Workshop
// Works_018
// I2C Communication (2)

/**
 * Previous sketch looks unorganized. Its time to tidy-up the code.
 */

#include <Wire.h>
// We make our own library in Arduino!
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

// Go to Try_003

