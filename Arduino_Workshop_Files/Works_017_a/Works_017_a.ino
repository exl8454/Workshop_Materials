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

  /* Start writing from here */
  bitA = 0b00000001;
  bitB = 0b00000001;

  printBits();

  bitA = bitA << 2;
  bitB = bitB >> 2;
  printBits();

  bitB = 0b00000111;
  bitB = bitB >> 2;
  printBits();

  bitA = 0b00000001;
  bitB = 0b00000010;
  bitC = bitA | bitB;
  printBits();

  bitA = 0b00000001;
  bitB = 0b00000001;
  bitC = bitA | (bitB << 1);
  printBits();

  bitA = 0b11111110;
  bitB = 0b11111100;
  bitC = bitA & bitB;
  printBits();

  bitA = 0b10101100;
  bitB = 0b00000100;
  bitC = bitA & bitB;
  printBits();

  bitA = 0b10101100;
  bitB = 0b11111111;
  bitC = bitA ^ bitB;
  printBits();

  bitA = 0b10101010;
  bitB = ~bitA;
  bitC  = bitA | bitB;
  printBits();

  bitA = 0b10101100;
  bitB = 0b10001111;
  output = (bitA << 8) | bitB;
  printBits();
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
