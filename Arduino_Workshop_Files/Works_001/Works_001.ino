/* Arduino Workshop
 Works_001
 Digital I/O (1) */

/**
 * First thing to do with Digital Input and Output, we will try to send signal high and signal low output.
 * When signal is set to HIGH, it means digital pin is sending constant 5V out.
 * When signal is set to LOW, it means digital pin is sending constant 0V out.
 */

/* Variables */
int ledPin = 9;
float blink_interval = 0.5f;

void setup()
{
  /**
   * pinMode(pin_number, pin_mode) allows you to setup a pin
   * pinMode function does port direction and port input/output
   * status for you.
   * 
   * Three types of pin modes are available;
   * OUTPUT: Pin is enabled to output a data
   * INPUT: Pin is enabled to read a data
   * INPUT_PULLUP: Pin is enabled to read a data, with internal pull-up
   * resistor
   * 
   * We will try other two later on
  */
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  /**
   * digitalWrite(pin_number, value) allows you to change signal on the target pin.
   * 
   * HIGH or 1 will set voltage on target pin to logic HIGH voltage.
   * 
   * LOW or 0 will set voltage on target pin to logic low voltage.
   */
   digitalWrite(ledPin, HIGH);
   /**
    * delay(delay_value_in_millisecond) allows you to tell microcontroller to halt
    * itself with given time.
    * 
    * Parameter is in millisecond, so if you want to wait for 1 second, you need to give
    * 1000 as parameter
    */
    delay((int) (1000 * blink_linterval));

    digitalWrite(ledPin, LOW); // What this will do?
    delay((int) (1000 * blink_interval)); // What could be other way to delay for 500ms?
}
