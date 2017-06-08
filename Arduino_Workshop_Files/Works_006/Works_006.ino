// Arduino Workshop
// Works_006
// Analog Devices (2)

/**
 * Now that we know we can read voltage from potentiometers,
 * lets try to send this value through PWM pins as cycle.
 */

// Variables
static const int blue = 6;
static const int analogPin = 0;

static int cycle = 0; // 0% cycle

void setup()
{
  pinMode(blue, OUTPUT);
}

void loop()
{
  cycle = analogRead(analogPin);
  cycle = map(cycle, 0, 1023, 0, 255);
  analogWrite(blue, cycle);
}
