/* Arduino Workshop
 Works_005
 Analog Devices */

/**
 * Analog devices can be read by Arduino's Analog pins.
 * These pins are marked with A# on Arduino boards.
 * By default, Arduino with 5V system has default reference voltage of 5V.
 * 
 * Note that analog pins is read-only. To write an analog signal, use
 * PWM pins.
 */

/* Variables */
/* No variables on this one! */
void setup()
{
  Serial.begin(9600); // We will talk about this later
}

void loop()
{
  float val = analogRead(0);
  val = (val / 1024.f) * 5.0f;
  Serial.println(val);
  delay(100);
}
