// Arduino Workshop
// Exercise_002
// Button Matrix

/**
 * Let's make button matrix. This is how common keyboards and keypads works.
 * Just like LED Matrix, use pin 2 and 3 as row, 4 and 5 as column
 */

// Variables
int row1 = 2;
int row2 = 3;
volatile int col1 = 4;
volatile int col2 = 5;
volatile int led11 = 8;
volatile int led12 = 9;
volatile int led21 = 10;
volatile int led22 = 11;
volatile int state11 = LOW;
volatile int state12 = LOW;
volatile int state21 = LOW;
volatile int state22 = LOW;

void setup()
{
}

void loop()
{
}
