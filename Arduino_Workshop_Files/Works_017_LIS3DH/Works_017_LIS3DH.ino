#include <LIS3DH.h>

float gx, gy, gz;
void setup()
{
  Serial.begin(115200);
  startSensor();
  delay(1000);
}

void loop()
{
  readSensor(&gx, &gy, &gz);
  Serial.print(gx); Serial.print(" ");
  Serial.print(gy); Serial.print(" ");
  Serial.print(gz); Serial.println(" ");
  delay(100);
}
