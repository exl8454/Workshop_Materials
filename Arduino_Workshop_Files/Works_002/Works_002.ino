/* Arduino Workshop
 Works_002
 Digital I/O (2) */

/**
 * In digital I/O (2), we will talk about digital signal INPUT.
 * There are two different type of input method. regular input and pull-up input.
 * This sketch will focus on regular input method.
 */

/* Variables */
int ledPin = 9;
int buttonPin = 3;

void setup()
{
  pinMode(ledPin, OUTPUT); // Set pin 9 as output
  pinMode(buttonPin, INPUT); // Set pin 3 as input

  digitalWrite(buttonPin, LOW); // To clear any previous state, we set pin signal as low
  /**
   * If we use the pin 'as is', you will notice LED blinking at random time. This is because
   * signal has no designated path before button is pressed. This phenomena is called floating.
   * 
   * Floating, depending on an application, can be negligible or can be disastrous. Either way,
   * removing floating is always helpful. Since we want our input reading to be 0V while button
   * is not pressed, we will add PULL-DOWN Resistor.
   */
}

void loop()
{
  /**
   * digitalRead(pin_number) allows us to read signal on the specific pin. If a voltage reading
   * on the pin is bigger than 3.0V, it returns HIGH. If a voltage reading on the pin is less 
   * than 1.5V, it returns LOW. Note that these threshold values changes on 3.3V system.
   */
  int pinRead = digitalRead(buttonPin);

  if(pinRead == HIGH)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
