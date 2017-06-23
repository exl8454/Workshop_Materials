/*
// Arduino Workshop
// Exercise_002
// Button Matrix
*/

/**
 * Let's make button matrix. This is how common keyboards and keypads works.
 * Just like LED Matrix, use pin 2 and 3 as row, 4 and 5 as column
 */

/* Variables */
int row1 = 2;
int row2 = 3;
int col1 = 4;
int col2 = 5;
int lrow1 = 8;
int lrow2 = 9;
int lcol1 = 10;
int lcol2 = 11;
int state11 = LOW;
int state12 = LOW;
int state21 = LOW;
int state22 = LOW;

void offAll()
{
  digitalWrite(lrow1, LOW);
  digitalWrite(lrow2, LOW);
  digitalWrite(lcol1, HIGH);
  digitalWrite(lcol2, HIGH);
}

void setLED()
{
  if(state11)
  {
    digitalWrite(lrow1, HIGH);
    digitalWrite(lcol1, LOW);
  }
  delay(2);
  offAll();
  if(state12)
  {
    digitalWrite(lrow1, HIGH);
    digitalWrite(lcol2, LOW);
  }
  delay(2);
  offAll();
  if(state21)
  {
    digitalWrite(lrow2, HIGH);
    digitalWrite(lcol1, LOW);
  }
  delay(2);
  offAll();
  if(state22)
  {
    digitalWrite(lrow2, HIGH);
    digitalWrite(lcol2, LOW);
  }
  delay(2);
  offAll();
}

void setup()
{
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(col1, INPUT);
  pinMode(col2, INPUT);

  pinMode(lrow1, OUTPUT); pinMode(lcol1, OUTPUT);
  pinMode(lrow2, OUTPUT); pinMode(lcol2, OUTPUT);

  offAll();
}

void loop()
{
  setLED();
  
  digitalWrite(row1, HIGH);
  if(digitalRead(col1))
  {
    while(digitalRead(col1));
    state11 = !state11;
  }
  if(digitalRead(col2))
  {
    while(digitalRead(col2));
    state12 = !state12;
  }
  digitalWrite(row1, LOW);

  digitalWrite(row2, HIGH);
  if(digitalRead(col1))
  {
    while(digitalRead(col1));
    state21 = !state21;
  }
  if(digitalRead(col2))
  {
    while(digitalRead(col2));
    state22 = !state22;
  }
  digitalWrite(row2, LOW);
}

