/*
 * Arduino Workshop
 * Works_022_b
 * Micro/SD Card Reader/Writer!
 * 
 * To setup Micro SD Card Reader with Arduino, connect pins as below
 * Arduino Pin    | SD Card Pin
 * Pin 11         | MOSI
 * Pin 12         | MISO
 * Pin 13         | CLK(SCK)
 * Pin 4          | CD(CS)
 */

/* We will learn how to write to SD Card continously */

#include <SPI.h>
#include <SD.h>

/* Variables */
File file;
bool writing = true;

void setup()
{
  Serial.begin(115200);
  while(!Serial);

  Serial.println("Initializing SD Card...");

  if(!SD.begin(4)) /* SD library searches CS pin, which, in our case, pin 4. */
  {
    Serial.println("Init Failed");
    return;
  }
  Serial.println("Init Done");
}

void loop()
{
  /* Check if any input was made */
  if(Serial.available())
  {
    /* Change write status */
    writing = !writing;
    Serial.print("Writing status: ");
    Serial.println(writing);
    while(Serial.available())
      Serial.read();
  }
  
  /* Read Potentiometer */
  int value = analogRead(0);

  /* Write to file if we are in writing mode */
  if(writing)
  {
    file = SD.open("Data.txt", FILE_WRITE);
    if(file)
    {
      file.println(value);
      file.close();
    }
    
  }
}

