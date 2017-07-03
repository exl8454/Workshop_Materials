/*
 * Arduino Workshop
 * Works_016_b
 * USART Communication (5)
 * 
 * LED Control...more
 */

/* Variables */
static const int red = 9;
static const int yellow = 10;
static const int green = 11;

char data[];

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  Serial.begin(9600);
}

