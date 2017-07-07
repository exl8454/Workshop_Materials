/*
 * Arduino Workshop
 * Works_013
 * USART Communication (2)
 * 
 * In this sketch, we will look into different ways to read a data from computer
 */

 /* Variables */
byte data[5];
String line; /* Though supported by Arduino, highly discouraged for data parsing */

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  /**
   * Serial.read() reads in SINGLE byte.
   */
  byte data = Serial.read();
  Serial.print("Received: ");
  Serial.println((char) data);

  /**
   * Serial.readBytes(buffer, size) reads in multiple bytes.
   * This function terminates itself if serial timeout is 
   * reached.
   */
  /* Serial.readBytes(&data, 5); */

  /**
   * Serial.readBytesUntil(char, buffer, size) reads in multiple
   * bytes until given terminator is detected. However, if buffer
   * reaches its limit, it also terminates itself.
   */
  /* Serial.readBytesUntil('\n', &data, 5); */

  /**
   * Serial.readString() reads data as string type.
   */
  /* line = Serial.readString(); */

  /**
   * Serial.readStringUntil(char) reads data as string type until
   * given terminator is detected.
   */
  /* line = Serial.readStringUntil('\n'); */
}
