/*
 * Arduino Workshop
 * Works_023
 * Rotary Encoder
 */

/* Variables */
int pinA = 3;
int pinB = 4;
int pos = 0;
int posA;
int posB;
int _posA = LOW; /* Last position */

void setup()
{
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  Serial.begin(115200);
  while(!Serial);
}

void loop()
{
  /* How Encoder Works */
  /*
   * Encoder works by reading two different pin positions
   * When pin A changes from HIGH to LOW, if pin B was at
   * HIGH, this will indicate encoder is going CLOCKWISE.
   * If pin B was read LOW, this will indicate encoder is
   * going COUNTER-CLOCKWISE.
   */
  posA = digitalRead(pinA);
  posB = digitalRead(pinB);
  
  if(!posA && _posA)
  {
    if(posB)
    {
      pos++;
    }
    else
    {
      pos--;
    }
    Serial.println(pos);
  }
  _posA = posA;
}

