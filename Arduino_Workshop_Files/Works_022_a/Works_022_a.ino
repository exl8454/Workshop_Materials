/*
 * Arduino Workshop
 * Works_022_a
 * Micro/SD Card Reader/Writer!
 * 
 * To setup Micro SD Card Reader with Arduino, connect pins as below
 * Arduino Pin    | SD Card Pin
 * Pin 11         | MOSI
 * Pin 12         | MISO
 * Pin 13         | CLK(SCK)
 * Pin 4          | CD(CS)
 */

#include <SPI.h> /* SD Card reader uses SPI communication */
#include <SD.h> /* Arduino SD Card Library */

/* Variables */
File file;

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

  file = SD.open("foo.txt", FILE_WRITE);

  if(file)
  {
    Serial.println("Writing to file...");
      file.println("Testing Testing 1 2 3");
      file.close(); /* Be sure to close file each time you write! */
    Serial.println("Done");
  }
  else
  {
    Serial.println("File didn't open!");
  }

  file = SD.open("foo.txt");
  if(file)
  {
    Serial.println("Reading foo.txt...");

    while(file.available())
    {
      Serial.write(file.read());
    }

    file.close();
  }
  else
  {
    Serial.println("File didn't open!");
  }
}

void loop()
{
  /* Nothing in Loop... */
}

