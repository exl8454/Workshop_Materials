/* Arduino Workshop
 Works_003
 Digital I/O (3) */

/**
 * In digital I/O (3), we will talk about digital signal INPUT in other method.
 * In this sketch, pull-up resistor is used
 */

/* Variables */
int ledPin = 9;
int buttonPin = 3;
int state = LOW;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  // To enable pull up, set the signal HIGH
  digitalWrite(buttonPin, HIGH);
}

void loop()
{
  /**
   * For this sketch, we will try different approach on button state. Remember
   * the state variable. We will negate the saved state each time when button is
   * pressed.
   * 
   * For button, we check if button is still held down. This means we wait until
   * signal goes back to HIGH on input pin. When pin state changes to HIGH, we
   * negate the state.
   */
  if(digitalRead(buttonPin) == LOW)
  {
    while(digitalRead(buttonPin) == LOW);
    state = !state;
  }

  digitalWrite(ledPin, state);
}
