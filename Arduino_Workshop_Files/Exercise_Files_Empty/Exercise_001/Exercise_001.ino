/*
// Arduino Workshop
// Exercise_001
// Voltmeter
*/

/**
 * Lets try to make a simple voltmeter. To think about, Arduino cannot take voltage
 * bigger than 5V. So to measure a voltage bigger than 5V, we need a voltage divider.
 */

/* Variables */
float voltage;
float source;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Voltage: ");
  /* How can you convert analog read to voltage output? */
  /* Enter your code below */
  Serial.println(source);
}
