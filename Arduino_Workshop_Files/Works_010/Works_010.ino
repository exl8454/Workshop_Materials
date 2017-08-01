/*
*  Arduino Workshop
 * Works_010
*  Tasking multiple things (2)
 */

/*
*  Previous example doesn't blink all LEDs at the same time.
 * 
*  This sketch will show you first step into multi-tasking; the state machine.
 * State machine basically checks on current state of a certain pins, such as
*  LED pins, and depending on the state of the pin, a machine does certain
 * operation.
*/

/* Variables */
const static int green = 9;
const static int yellow = 10;
const static int red = 11;
static int yellowState = LOW;
static int redState = LOW;

long lastCheck_G = 0;
long lastCheck_Y = 0;
long lastCheck_R = 0;
long interval_G = 30;
long interval_Y = 500;
long interval_R = 1000;

static int brightness_G = 0;
static int fadeAmount_G = 5;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop()
{
  unsigned long currentCheck = millis();

  if(currentCheck - lastCheck_G > interval_G)
  {
    lastCheck_G = currentCheck;
    analogWrite(green, brightness_G);
    brightness_G = brightness_G + fadeAmount_G;
  
    if (brightness_G <= 0 || brightness_G >= 255)
    {
      fadeAmount_G = -fadeAmount_G;
    }
  }

  if(currentCheck - lastCheck_Y > interval_Y)
  {
    lastCheck_Y = currentCheck;
    yellowState = !yellowState;

    digitalWrite(yellow, yellowState);
  }

  if(currentCheck - lastCheck_R > interval_R)
  {
    lastCheck_R = currentCheck;
    redState = !redState;

    digitalWrite(red, redState);
  }
}
