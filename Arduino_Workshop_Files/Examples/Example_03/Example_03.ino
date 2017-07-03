/*
 * Arduino Workshop
 * Example_03.ino
 * This example shows how to incorporate data from IMU with other devices,
 * such as computer
 */

#include <Workshop_IMU.h>

void setup()
{
  Serial.begin(115200);
  startSensor();

  if(sensor_status != 0b11)
  {
    if(sensor_status == 0b10)
      Serial.println("No Accelerometer!");
    if(sensor_status == 0b01)
      Serial.println("No Gyroscope!");
    while(1);
  }

  Serial.println("Staring...");
  delay(1000);
}

void loop()
{
  readSensors();
  //Serial.print("Accl: "); Serial.print(a[0]); Serial.print(" "); Serial.print(a[1]); Serial.print(" "); Serial.println(a[2]); 
  Serial.print("Gyro: "); Serial.print(g[0]); Serial.print(" "); Serial.print(g[1]); Serial.print(" "); Serial.println(g[2]);
  delay(100);
}

