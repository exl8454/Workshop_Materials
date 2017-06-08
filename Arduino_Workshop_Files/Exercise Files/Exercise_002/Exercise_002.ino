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
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(col1, INPUT);
  pinMode(col2, INPUT);

  pinMode(led11, OUTPUT); pinMode(led12, OUTPUT);
  pinMode(led21, OUTPUT); pinMode(led22, OUTPUT);
}

void loop()
{
  digitalWrite(row1, HIGH);
  if(digitalRead(col1))
  {
    while(digitalRead(col1));
    state11 = !state11;
    digitalWrite(led11, state11);
  }
  if(digitalRead(col2))
  {
    while(digitalRead(col2));
    state12 = !state12;
    digitalWrite(led12, state12);
  }
  digitalWrite(row1, LOW);

  digitalWrite(row2, HIGH);
  if(digitalRead(col1))
  {
    while(digitalRead(col1));
    state21 = !state21;
    digitalWrite(led21, state21);
  }
  if(digitalRead(col2))
  {
    while(digitalRead(col2));
    state22 = !state22;
    digitalWrite(led22, state22);
  }
  digitalWrite(row2, LOW);
}
