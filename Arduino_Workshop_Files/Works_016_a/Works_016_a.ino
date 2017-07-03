/*
 * Arduino Workshop
 * Works_016_a
 * USART Communication (5)
 * 
 * A good example of data handling
 * 
 * Obviously, uC does not know what kind of data is coming in.
 * To sort data out and handle our execution from command,
 * WE need to short hte data out.
 */
 
/* Variables */
static const int red = 9;
static const int yellow = 10;
static const int green = 11;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0)
  {
    char led = Serial.read();

    while(Serial.available() < 4);
    char val[4];
    Serial.read();
    val[0] = Serial.read();
    val[1] = Serial.read();
    val[2] = Serial.read();
    val[3] = '\0';
    int pwm = atoi(val);
    
    Serial.print("Pin: "); Serial.println(led);
    Serial.print("PWM: "); Serial.println(pwm);
    
    switch(led)
    {
      case 'R':
      case 'r':
        analogWrite(red, pwm);
      break;
      case 'Y':
      case 'y':
        analogWrite(yellow, pwm);
      break;
      case 'G':
      case 'g':
        analogWrite(green, pwm);
      break;
    }
  }
  Serial.flush();
}
