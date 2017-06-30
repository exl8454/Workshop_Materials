/*
 * Arduino Workshop
 * Works_017_b
 * I2C Communication (1)
 * 
 * Now we got through basic bitwise operation, let's look at Arduino's default
 * I2C library
 */

/*
 * Wire.h is Arduino's library for I2C. It is built for us so we don't have to
 * micromanage the signal controls for I2C Communication!
 */
#include <Wire.h>

void setup()
{
  /* To start I2C Communication, use Wire.begin() function. No parameters */
  Wire.begin();

  /* To start transmission to target slave device, use Wire.beginTransmission */
  Wire.beginTransmission(0x00); /* Device address as parameter! */
  
  /* Once you called to slave device, use Wire.write() to send data to slave! */
  Wire.write(0x00); /* Although you can write as much as you can, do not exceed 8 bits! */
  
  /* To request data from slave, use Wire.requestFrom() */
  Wire.requestFrom(0x00, 1); /* First use device address, then use number of bytes to read */

  /* To read single bit from slave, use Wire.read() */
  Wire.read(); /* No parameter is needed */

  /* We can also use Wire.available() to check how many bytes of data is sitting on I2C data line */
  while(!Wire.available() >= 5); /* This will loop infinitley until available data is more than 5 bytes! */

  /* To close I2C Communication with slave device, use Wire.endTransmission() */
  Wire.endTransmission(); /* No parameter is needed */

  /* Generic sequence for writing to slave (Assuming Wire.begin() is already called) */
  Wire.beginTransmission(0x00);
  Wire.write(0x00);
  Wire.endTransmission();

  /* Generic sequence for reading from slave */
  Wire.beginTransmission(0x00);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.requestFrom(0x00, 1);
  byte data = Wire.read();
}

void loop()
{
  /* No loop function! */
}

