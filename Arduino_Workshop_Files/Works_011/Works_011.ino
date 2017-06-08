// Arduino Workshop
// Works_011
// Tasking multiple things (3)

/**
 * Previous sketch showed how using millis(), but in order to check if it was time to do
 * a task, we had to call millis() every loop.
 * 
 * This time, instead of checking the time for each loop, we will use internal interrupt
 * so the microcontroller will call a specific method.
 * 
 * Atmega328P has 3 timers; Timer0, Timer1, and Timer2. Timer0 is used to call millis()
 * function in Arduino, so Timer0 is what we want to use to interrupt.
 */

// Variables
const static int green = 9;
const static int yellow = 10;
const static int red = 11;
const static int blue = 6;
static int yellowState = LOW;
static int redState = LOW;

long lastCheck_G = 0;
long lastCheck_Y = 0;
long lastCheck_R = 0;

long interval_G = 30;
long interval_Y = 500;
long interval_R = 1000;

long lastCheck_B = 0;
long interval_B = 100;

static int brightness_G = 0;
static int fadeAmount_G = 5;

static int blue_pwm = 0;
static int cycle = 5;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  
  /**
   * OCRxA is Output Compare Register. OCR0A is compared
   * to Timer0, and if values are matching, interrupt
   * function, also called ISR(Interrupt Service Routine)
   * is called.
   * Here, we set interrupt value to a certain value(0xAF)
   * so compare interrupt can be called. This value must be
   * between 0 to 255(0xFF), so Timer0(0~255) can be matched.
   */
  OCR0A = 0xAF;
  /**
   * TIMSKx is Timer interrupt mask. This sets interrut
   * mode for Timer. TIMSK0 sets interrupt mask for Timer0.
   * OCIExA is Output Compare Interrupt Enable. This is the
   * bit value to enable compare interrupt for selected timer.
   * OCIE0A enables compare interrupt for Timer0
   */
  TIMSK0 |= _BV(OCIE0A);
}

ISR(TIMER0_COMPA_vect)
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

  if(currentCheck - lastCheck_B > interval_B)
  {
    lastCheck_B = currentCheck;
    analogWrite(blue, blue_pwm);
    blue_pwm = blue_pwm + cycle;
  
    if (blue_pwm <= 0 || blue_pwm >= 255)
    {
      cycle = -cycle;
    }
  }
}

void loop()
{
  /**
   * This is empty. Everything is done inside interrupt loop!
   */
}

// Go to Try_002

