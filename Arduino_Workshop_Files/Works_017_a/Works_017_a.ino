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
  Serial.print("BitA: "); Serial.print(bitA, BIN); Serial.print(" is "); Serial.println(bitA, DEC);
  Serial.print("BitB: "); Serial.print(bitB, BIN); Serial.print(" is "); Serial.println(bitB, DEC);
  Serial.print("BitC: "); Serial.print(bitC, BIN); Serial.print(" is "); Serial.println(bitC, DEC);
  Serial.print("16-bit Output: "); Serial.print(output, BIN); Serial.print(" is "); Serial.println(output, DEC);
  Serial.println();
}

void loop()
{
  /* Not using loop function */
}
