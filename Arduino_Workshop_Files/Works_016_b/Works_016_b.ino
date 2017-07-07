/*
 * Arduino Workshop
 * Works_016_b
 * USART Communication (5)
 * 
 * LED Control...more
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Variables */
static const int red = 9;
static const int yellow = 10;
static const int green = 11;

/* 3 characters for color, 3 digits for value, and single space for delimeter*/
char data[21]; /* We are assuming we will not have more than 21 characters in single data */
char *delim = " ";
char *token;

char *pin;
int value;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  Serial.begin(115200);
}

/* [RED,YEL,GRN] [PWM] */
void loop()
{
  while(Serial.available())
  {
    Serial.readBytes(data, 7);
    token = strtok(data, delim);
    while(token != NULL)
    {
      if(!strcmp(token, "RED") || !strcmp(token, "YEL") || !strcmp(token, "GRN"))
      {
        pin = token;
      }
      else
      {
        value = atoi(token);
      }
      token = strtok(NULL, delim);
    } /* end of token check loop */
    Serial.print("PIN: "); Serial.println(pin);
    Serial.print("PWM: "); Serial.println(value);
  
    if(!strcmp(pin, "RED"))
      analogWrite(red, value);
    if(!strcmp(pin, "YEL"))
      analogWrite(yellow, value);
    if(!strcmp(pin, "GRN"))
      analogWrite(green, value);
  } /* end of data check loop */
}

