/*
 * Arduino Workshop
 * Exercise_003.ino
 * USART Communication DIY
 * 
 * You are to send two three-digit number and 3 character instruction so Arduino can perform
 * numerical expressions. 3-digit must have 0 padded on left if number is less than 100.
 * 
 * Arduino also must be able to perform bitwise operation on two integer to long type. That is,
 * perform bitwise operation on two 16-bits to create 32-bit long type.
 * 
 * Arduino must be able to parse negative number without problem.
 * 
 * Also, Arduino must be able to perform multiple commands sent from single line. That is, 
 * following instruction should work without a problem.
 * -125 125 ADD 050 050 SUB
 * 
 * Each command should not exceed 100 characters (It is limited by the line variable)
 * 
 * Here are the list of commands for numerical expressions.
 * 
 * 3-char command | Description
 * ----------------------------
 * ADD            | Adds two numbers
 * SUB            | Subtracts two numbers
 * MUL            | Multiplies two numbers
 * DIV            | Divides two numbers
 * BSL            | Bit Shift Left. Fisrt number will be shifted 16 bits. Prints binary format
 * BSR            | Bit Shift Right. Second number will be shifted 16 bits. Prints binary format
 * 
 * For each instruction, funcions are given; which means when two numbers and a command is parsed,
 * it should be able to return result through a function.
 * 
 * Do not worry about floating point division.
 * 
 * Hint: atoi(char *digit) returns 0 if there was nothing parsed.
 * 
 * Following command should give proper result.
 * 100 -050 ADD 100 -050 SUB -010 -050 MUL 200 025 DIV 055 250 BSL 550 124 BSR
 * 
 * Outputs
 * A: 100 1100100
 * B: -50 11111111111111111111111111001110
 * A + B: 50
 * 
 * A: 100 1100100
 * B: -50 11111111111111111111111111001110
 * A - B: 150
 * 
 * A: -10 11111111111111111111111111110110
 * B: -50 11111111111111111111111111001110
 * A * B: 500
 * 
 * A: 200 11001000
 * B: 25 11001
 * A / B: 8
 * 
 * A: 55 110111
 * B: 250 11111010
 * (A << 16) | B: 1101110000000011111010
 * 
 * A: 550 1000100110
 * B: 124 1111100
 * A | (B << 16): 11111000000001000100110
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char line[100];
char *delim = " ";
char *token;

int A, B;
boolean hasA = false, hasB = false;
int type;

void printBits();
void checkIfCommand(char *token);
void ADD(int A, int B);
void SUB(int A, int B);
void MUL(int A, int B);
void DIV(int A, int B);
void BSL(int A, int B);
void BSR(int A, int B);
  
void setup()
{
  Serial.begin(115200);
}

void loop()
{
}

void checkIfCommand(char *token)
{
}

void ADD(int A, int B)
{
  int sum = A + B;
  printBits();
  Serial.print("A + B: "); Serial.println(sum);
  Serial.println();
}

void SUB(int A, int B)
{
  int sub = A - B;
  printBits();
  Serial.print("A - B: "); Serial.println(sub);
  Serial.println();
}

void MUL(int A, int B)
{
  int mul = A * B;
  printBits();
  Serial.print("A * B: "); Serial.println(mul);
  Serial.println();
}

void DIV(int A, int B)
{
  int diV = A / B;
  printBits();
  Serial.print("A / B: "); Serial.println(diV);
  Serial.println();
}

void BSL(int A, int B)
{
  long bsl = ((long)A << 16) | (long)B;
  printBits();
  Serial.print("(A << 16) | B: "); Serial.println(bsl, BIN);
  Serial.println();
}

void BSR(int A, int B)
{
  long bsr = (long)A | ((long)B << 16);
  printBits();
  Serial.print("A | (B << 16): "); Serial.println(bsr, BIN);
  Serial.println();
}

void printBits()
{
  Serial.print("A: "); Serial.print(A); Serial.print(" "); Serial.println(A, BIN);
  Serial.print("B: "); Serial.print(B); Serial.print(" "); Serial.println(B, BIN);
}

