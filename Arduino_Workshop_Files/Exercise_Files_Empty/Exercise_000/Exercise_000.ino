// Arduino Workshop
// Exercise_000
// LED Matrix!

/**
 * Time to make simple 2 by 2 LED matrix!
 * Use pin 2 and 3 as row, 4 and 5 as column.
 * 
 * We will be using rows as positive and columns as negative
 */

// Variables
int row1 = 2;
int row2 = 3;

int col1 = 4;
int col2 = 5;

void setup()
{
  pinMode(row1, OUTPUT); digitalWrite(row1, LOW);
  pinMode(row2, OUTPUT); digitalWrite(row2, LOW);
  pinMode(col1, OUTPUT); digitalWrite(col1, LOW);
  pinMode(col2, OUTPUT); digitalWrite(col2, LOW);
}

// Do these ONE AT A TIME!
// 1. Turn on row 1
// 2. Turn on column 1
// 3. Turn on column 2
// 4. From here, reset all columns
// 5. Turn off row1, then turn on row 2
// 6. Reset all rows and columns
// 7. Now, try to turn on LEDs on (1,1) and (2,2)
void loop()
{
}

