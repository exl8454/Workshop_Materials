/*
 * Arduino Workshop
 * Works_012
 * USART Communication (1)
 * 
 * Arduino has default serial communication pin using
 * USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
 * protocol.
 */

/*
 * Variables
 * No variables on this one!
 */
 
void setup()
{
  /**
   * Serial.begin(bps, config) allows arduino to open USART port using
   * given bps (Bits Per Second). Config parameter, by default, is set
   * to 8N1. 8N1 has three parts.
   * 8 : Data sent/received has 8 bits
   * N : NO Parity type. Parity is the lowest level of error checking.
   * 1 : There is one stop bit. Stop bits indicate USART line is idle
   * or transmitting/receving.
   * 
   * You can change configuration for different setup.
   */
  Serial.begin(115200);
}

void loop()
{
  /**
   * Serial.println(data) sends data FROM Arduino TO computer.
   * Note that ln indicates sent data has line change delimiter as well.
   */
  Serial.println(analogRead(0));
  delay(10);
}
