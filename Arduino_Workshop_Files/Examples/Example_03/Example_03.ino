/*
 * Arduino Workshop
 * Example_03.ino
 * This example shows how to incorporate data from IMU with other devices,
 * such as computer
 */

#include <LSM303_L3GD20H.h>

int i;
float roll = 0, pitch = 0, yaw = 0;

void setup()
{
  Serial.begin(115200);
  startSensor();
}

void loop()
{
  if(Serial.available())
  {
    Serial.read();
    readSensor();
    roll = rpy[0]; pitch = rpy[1]; yaw = rpy[2];
    for(int i = 1; i < 9; i ++)
    {
      readSensor();
      roll += rpy[0]; pitch += rpy[1]; yaw += rpy[2];
    }
    
    roll /= 10; pitch /= 10; yaw /= 10;

    Serial.print("RPYA:"); Serial.print(roll);
    Serial.print(","); Serial.print(pitch);
    Serial.print(","); Serial.println(yaw);
  }
  //readSensor();
  //Serial.print(rpy[0]); Serial.print(" "); Serial.print(rpy[1]); Serial.print(" "); Serial.println(rpy[2]);
  //delay(500);
}

