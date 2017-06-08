// Arduino Workshop
// Works_004
// Digital I/O (4)

/**
 * In this sketch, we will use PWM on certain pins.
 * PWM stands for Pulse Width Modulator. Instead of sending HIGH voltage through out
 * given time, PWM goes HIGH-LOW with given duty cycle, averaging voltage output based
 * on duty cycle. For example, 50% duty cycle on 5V signal pin would output 2.5V as
 * result.
 * 
 * We will use two buttons and one LED for this sketch
 */

// Variables
int ledPin = 9;
int upPin = 3;
int dnPin = 2;
int cycle = 0;
int amount = 25;

void setup()
{
  pinMode(ledPin, OUTPUT);

  pinMode(upPin, INPUT_PULLUP);
  pinMode(dnPin, INPUT_PULLUP);

  digitalWrite(upPin, HIGH);
  digitalWrite(dnPin, LOW);
}

void loop()
{
  if(digitalRead(upPin) == LOW)
  {
    while(digitalRead(upPin) == LOW);
    cycle += amount;
    cycle = (cycle > 250) ? 250 : cycle;
  }

  if(digitalRead(dnPin) == LOW)
  {
    while(digitalRead(dnPin) == LOW);
    cycle -= amount;
    cycle = (cycle < 0) ? 0 : cycle;
  }

  /**
   * analogWrite(pin_number, value) allows us to send modulated signal with given duty cycle.
   * Duty cycle range is from 0 (0V) to 255 (5V). Note that this function only works with
   * digital pins with PWM capability. This cannot be used on analog pins!
   */
  analogWrite(ledPin, cycle);
}
