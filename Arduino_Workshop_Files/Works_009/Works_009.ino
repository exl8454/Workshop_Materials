// Arduino Workshop
// Works_009
// Tasking multiple things

/**
 * Blink blink!
 * At the end of this section, we should have three LEDs blinking at different rate,
 * at the same time.
 */
 
// Variables
const static int red = 11;
const static int yellow = 10;
const static int green = 9;

int brightness = 0;
int fadeAmount = 5;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  analogWrite(red, brightness);
  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255)
  {
    fadeAmount = -fadeAmount;
  }

  delay(30);

  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(500);

  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  delay(1000);
}

