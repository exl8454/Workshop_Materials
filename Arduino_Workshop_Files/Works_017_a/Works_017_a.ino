/*
 * Arduino Workshop
 * Works_017_a
 * I2C Communication (1)
 * 
 * Before we get into I2C, we will learn about bit controls
 */

int output;
byte bitA, bitB, bitC;

void printBits();

void setup()
{
  Serial.begin(9600);
}

void printBits()
{
  Serial.print("BitA: "); Serial.println(bitA, BIN);
  Serial.print("BitB: "); Serial.println(bitB, BIN);
  Serial.print("BitC: "); Serial.println(bitC, BIN);
  Serial.print("16-bit Output: "); Serial.println(output, BIN);
  Serial.println();
}

void loop()
{
  /* Not using loop function */
}
