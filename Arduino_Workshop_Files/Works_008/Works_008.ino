/*
// Arduino Workshop
// Works_008
// External Interrupts
*/

/**
 * This sketch shows how to use external interrupts using digital pins.
 */

/* Variables */
int ledPin = 9;
int cycleUp = 3;
int cycleDn = 2;

/** 
 * volatile keyword lets uC know that this variable is not stored
 * in a register, but to read it directly from the memory. Since
 * data is called directly from the memory, it slows process down.
 * Hence why we only make cycle variable volatile.
 */
volatile int cycle = 0;

int value;

void increaseCycle()
{
  cycle++;
  cycle = (cycle > 100) ? 100 : cycle;
}

void decreaseCycle()
{
  cycle--;
  cycle = (cycle < 0) ? 0 : cycle;
}

void setup()
{
  pinMode(ledPin, OUTPUT);

  pinMode(cycleUp, INPUT_PULLUP);
  pinMode(cycleDn, INPUT_PULLUP);

  /**
   * attachInterrupt(pin_number, ISR, mode) allows you to attach
   * external interruptions to certain pins. Note that you have
   * limited number of interruption pins, 2 on Arduino Uno.
   * 
   * Just like functions, ISR functions can be placed anywhere.
   * For workshop purpose, we will continue placing functions
   * after loop.
   */
  attachInterrupt(
    digitalPinToInterrupt(cycleUp),
    increaseCycle,
    FALLING);

  attachInterrupt(
    digitalPinToInterrupt(cycleDn),
    decreaseCycle,
    RISING);
}

void loop()
{
  value = map(cycle, 0, 100, 0, 255);
  analogWrite(ledPin, cycle);
}

