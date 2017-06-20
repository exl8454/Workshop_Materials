/*
// Arduino Workshop
// Works_007
// Functions
*/

/**
 * This sketch will show you how to create a function.
 * In C, in order to define a function, it must be called before
 * any function call. Which means order DOES matter. However,
 * Arduino handles it for us. (Remember we are complying with
 * C89 standard, so we will ignore Arduino's ease of use)
 * 
 * Other way for function declaration and function call is by
 * 'declaring' function, then 'define' later.
 */
 
/* Variables */
int ledPin = 9;
int cycleUp = 3;
int cycleDn = 2;
int cycle = 0;

///* Function declaration*/
//void WriteToPin(int pin, int value);

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(cycleUp, INPUT_PULLUP);
  pinMode(cycleDn, INPUT_PULLUP);

  digitalWrite(cycleUp, HIGH);
  digitalWrite(cycleDn, HIGH);
}

/**
 * Functions in Arduino does not need to be in
 * orders. (But we are complying with C89 standard so we are
 * declaring functions first!)
 */
void writeToPin(int pin, int value)
{
  /**
   * Re-maps value of cycle to 0~255
   * Since Arduino takes PWM value of 0 to 255,
   * we need to re-map it to 255
   * You can, however, use value of 0 to 255
   */
  value = map(value, 0, 100, 0, 255);
  analogWrite(pin, value);
}

void loop()
{
  if(digitalRead(cycleUp) == LOW)
  {
    while(digitalRead(cycleUp) == LOW);
    digitalWrite(13, HIGH);
    /* Increment cycle by 1 */
    cycle++;
    /* This is a simplyfied version of if statement */
    cycle = (cycle > 100) ? 100 : cycle;

    writeToPin(ledPin, cycle);
  }

  if(digitalRead(cycleDn) == LOW)
  {
    while(digitalRead(cycleDn) == LOW);
    digitalWrite(13, HIGH);
    /* Decrement cycle by 1 */
    cycle--;
    cycle = (cycle < 0) ? 0 : cycle;

    writeToPin(ledPin, cycle);
  }

  digitalWrite(13, LOW);
}

