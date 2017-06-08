// Arduino Workshop
// Works_007
// Functions

/**
 * This sketch will show you how to create a function.
 */
 
// Variables
int ledPin = 9;
int cycleUp = 3;
int cycleDn = 2;
int cycle = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);

  pinMode(cycleUp, INPUT_PULLUP);
  pinMode(cycleDn, INPUT_PULLUP);

  digitalWrite(cycleUp, HIGH);
  digitalWrite(cycleDn, HIGH);
}

/**
 * Functions in Arduino does not need to be in
 * orders. 
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
    // Increment cycle by 1
    cycle++;
    // This is a simplyfied version of if statement
    cycle = (cycle > 100) ? 100 : cycle;

    writeToPin(ledPin, cycle);
  }

  if(digitalRead(cycleDn) == LOW)
  {
    while(digitalRead(cycleDn) == LOW);
    // Decrement cycle by 1
    cycle--;
    cycle = (cycle < 0) ? 0 : cycle;

    writeToPin(ledPin, cycle);
  }
}

// Go to Try_000


