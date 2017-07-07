/*
 * Arduino Workshop
 * Works_014
 * USART Communication (3)
 * 
 * Notice we had empty lines in serial monitor.
 * Let's filter out what we read and send
 */

char data;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  /**
   * Serial.available() checks if there is data available
   * in the USART line. This function returns number of
   * available bytes in the serial line.
   */
  if(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.print("Received: ");
    Serial.println(data);
    Serial.print("Available :"); Serial.println(Serial.available());
  }
}
