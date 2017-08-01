/*
*  Arduino Workshop
 * Exercise_004
*  Fading while moving
 *  
*  At the end of this exercise, we should have 3 LEDs fading continuously
 * without any interruption. Also, with two buttons, user must be able to
*  select which LED to fade.
 *  
*  Key Requirements
 * 1. Use interrupts for button input.
*  2. Use timer interrupt to fade LED.
 * 3. Only one LED should be fading at a time.
*  4. When shifting LED, previous LED must set itself to
 * maximum brightness.
*  5. At the beginning, led_1 should be fading.
 * 6. Fading interval is 50ms, with fading amount of 5.
*  7. At the end, loop() function should be empty.
 *  
*  Hints
 * 1. Buttons uses pull-up resistors.
*  2. Remember external interrupt pins?
 * 3. Remember minimum and maximum PWM value?
*  4. Remember timer masking?
 * 
*  Do not alter given variables! Only add/remove/modify custom variables!
 */

/* Variables (Given) */
int buttonLeft = 2;
int buttonRight = 3;

int led_1 = 9;
int led_2 = 10;
int led_3 = 11;

/* Variables (Custom) */

void setup()
{
}

void loop()
{
}

