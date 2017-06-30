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

  bitA = 0b00000001;
  bitB = 0b00000001;

  /*
   * Notice when you print values out as binary, Arduino removes leading zeros.
   */
  printBits();

  /* 
   * To shift a bit byt given digit, use << or >>, depending on direction.
   * Here, we will shift bitA to left by 2 places then print the result
   * For bitB, we will shift bitB by right by 2 places
   */
  bitA = bitA << 2;
  bitB = bitB >> 2;
  printBits();

  /*
   * What happened to bitB? Lets try something else with bitB. This time, we will
   * assign 0b00000111 to bitB and shift to right by 2.
   * 
   * Notice we get 0b00000001. This shows any bits shifted outside maximum bit range
   * is dropped, and 0 is padded on left side.
   */
  bitB = 0b00000111;
  bitB = bitB >> 2;
  printBits();

  /*
   * Bit masking, or so name is called because we are 'stacking' bits on top of each
   * other, uses bitwise OR to mask bits.
   * Here, we assign 0b00000001 on bitA, and 0b00000010 on bitB, then mask the bit on
   * bitC
   */
  bitA = 0b00000001;
  bitB = 0b00000010;
  bitC = bitA | bitB;
  printBits();

  /*
   * Lets mix two techniques together. assign same bits to bitA and bitB, then shift
   * bitB by one and mask two together.
   */
  bitA = 0b00000001;
  bitB = 0b00000001;
  bitC = bitA | (bitB << 1);
  printBits();

  /*
   * Masking bits with bitwise OR means you are masking bits by 1. You can also mask
   * bits by 0 with bitwise AND. Here, we have two trailing zeros on bitB, which will
   * mask bitA.
   */
  bitA = 0b11111110;
  bitB = 0b11111100;
  bitC = bitA & bitB;
  printBits();

  /*
   * Bitwise AND is also used what we call bit querying. This technique is used to check
   * bit value at certain bit position. Here we want to check bit value 3 on bitA using 
   * bitB.
   */
  bitA = 0b10101100;
  bitB = 0b00001000;
  bitC = bitA & bitB;
  printBits();

  /*
   * We can also toggle bits with bitwise XOR. Toggling means you are turning bits on(1)
   * or off(0). Here, we want to toggle all bits in bitA using bitB. Any bits that were
   * off changes to on, while any bits that were on changes to off.
   */
  bitA = 0b10101100;
  bitB = 0b11111111;
  bitC = (bitA ^ bitB);
  printBits();

  /*
   * To inverse any bit in a variable, simply use bitwise NOT to negate all bits in a
   * single data. Here, we use bitwise NOT on bitA, save it to bitB, then mask both
   * on bitC, which results 0b11111111.
   */
  bitA = 0b10101010;
  bitB = ~bitA;
  bitC = bitA | bitB;
  printBits();

  /*
   * Previously, we've been masking bits between bits with same size. We can merge two
   * small-size bits into one larger bit areas. Here we merge two 8-bit into 16-bit
   * field. Notice the 1s on first 16 bits, this is because when printing binary format
   * with Serial.print functions, Arduino automatically converts values into 4-bytes LONG
   * format.
   */
  bitA = 0b10101100;
  bitB = 0b10001111;
  output = (bitA << 8) | (bitB);
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
