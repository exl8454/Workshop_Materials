// Used with Python Works_013.py

bool pressed = false;
bool terminated = false;
long timeBefore = 0L;

void setup()
{
  pinMode(13, OUTPUT); digitalWrite(13, LOW);
  
  pinMode(2, INPUT_PULLUP); digitalWrite(2, HIGH);
  attachInterrupt(digitalPinToInterrupt(2), button, RISING);

  pinMode(3, INPUT_PULLUP); digitalWrite(3, HIGH);
  attachInterrupt(digitalPinToInterrupt(3), terminate, RISING);

  Serial.begin(9600);
}

void button()
{
  pressed = true;
}

void terminate()
{
  terminated = true;
}

void loop()
{
  long timeNow = millis();
  long diff = timeNow - timeBefore;
  if(pressed && diff > 3000)
  {
    timeBefore = timeNow;
    Serial.println("T");
    pressed = false;
  }
  else if(diff > 3000)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
    pressed = false;
  }

  if(terminated)
  {
    Serial.println("S");
    while(terminated);
  }
}
