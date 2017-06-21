// Used with Python Works_013.py

bool pressed = false;
bool terminated = false;
long timeBefore = 0L;

int sendMail = 2;
int stopMail = 3;

void setup()
{
  pinMode(13, OUTPUT); digitalWrite(13, LOW);
  
  pinMode(sendMail, INPUT_PULLUP); digitalWrite(sendMail, HIGH);
  attachInterrupt(digitalPinToInterrupt(sendMail), button, RISING);

  pinMode(stopMail, INPUT_PULLUP); digitalWrite(stopMail, HIGH);
  attachInterrupt(digitalPinToInterrupt(stopMail), terminate, RISING);

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
