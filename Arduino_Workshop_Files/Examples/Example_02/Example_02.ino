/*
 * For Arduino Mega
 * DI:  Pin 51
 * DO:  Pin 50
 * SCK: Pin 52
 * CS:  Pin 53
 * 
 * Remember, This SD card library can only read/write to
 * FAT32 type allocation!
*/

#include <SPI.h>
#include <SD.h>

File myFile;
int led = 13;

void setup()
{
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  
  Serial.begin(9600);
  while(!Serial);

  Serial.println("SD Card Demo");
  if(!SD.begin(53))
  {
    Serial.println("No SD Card Detected");
    return;
  }
  Serial.println("SD Card Detected");
}

void loop()
{
  /* Write to file. File will be created if not found */
  myFile = SD.open("sample.txt", FILE_WRITE);

  /* If file is opened, start writing to file */
  if(myFile)
  {
    digitalWrite(led, HIGH);
    int value = analogRead(0);
    myFile.print("Value: "); myFile.print(value);
    myFile.print(" Time: "); myFile.print(millis());
    myFile.println();
    myFile.close();
    /* Remember to close file AFTER you wrote. */
  }
  digitalWrite(led, LOW);

  /* This is still unstable, since we don't know when to stop this process 
   * A simple start/stop button can fix it.
   */
}

