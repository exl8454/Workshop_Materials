/*
 * Arduino Workshop
 * Works_015
 * USART Communication (4)
 * 
 * Remote control of LED!
 */

/* Variables */
static const int red = 9;
static const int yellow = 10;
static const int green = 11;

static int red_state = LOW;
static int yellow_state = LOW;
static int green_state = LOW;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
  Serial.begin(115200);
}

void loop()
{
  if(Serial.available() > 0)
  {
    char led = Serial.read();
    switch(led)
    {
      case 'R':
      case 'r':
        red_state = !red_state;
      break;
      case 'Y':
      case 'y':
        yellow_state = !yellow_state;
      break;
      case 'G':
      case 'g':
        green_state = !green_state;
      break;
    }

    digitalWrite(red, red_state);
    digitalWrite(yellow, yellow_state);
    digitalWrite(green, green_state);

    Serial.print("Red is now "); Serial.println(red_state);
    Serial.print("Yellow is now "); Serial.println(yellow_state);
    Serial.print("Green is now "); Serial.println(green_state);
  }
}
