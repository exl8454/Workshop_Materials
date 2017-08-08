/*
*  Arduino Workshop
 * Works_020
*  Memory Management (3)
 */

/**
 * This memory management shows how to READ and WRITE from EEPROM.
 * Remember, EEPROM saves data as byte type.
 * 
 * For our reference...
 * Arduino Uno: 1kB EEPROM (0~1024)
 * Arduino Mega: 4kB EEPROM (0~4096)
 */

#include <EEPROM.h>

/* Variables */
int addr = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  EEPROM_Write(0, (byte) 3); /* Write single byte of 3(0b11) to address 0x00 */
  byte byteVal = EEPROM_Read(0); /* Read single byte from address 0x00 */

  Serial.print("Single byte: "); Serial.println(byteVal);
  
  EEPROM_WriteInt(1, 12345); /* Write 12345 to address 0x01 */
  int value = EEPROM_ReadInt(1); /* Read from address 0x01 */

  Serial.print("Integer Value: "); Serial.println(value);

  while(true);
}

/**
 * Theory of operation
 * For Arduino Uno/Mega, integer is 16-bit (2 bytes).
 * First we declare a byte pointer variable, and call memory address of value and
 * type cast it to byte. Note if byte is empty, it is casted as void type.
 * Upon successful declaration, byte pointer will point to first memory address of
 * value.
 * | 0 0 0 0 | 0 0 0 0 |
 *   ^
 * 
 * Then we iterate through size of integer value (in this case, 2 times), and move
 * through memory address. EEPROM function then write to starting address THEN move
 * to next address. Pointer variable also move to next address on given value.
 * 
 * Same idea applies to any data type bigger than a single byte.
 */
void EEPROM_WriteInt(int address, int value)
{
  byte* p = (byte*)(void*) &value;
  for(int i = 0; i < sizeof(value); i++)
  {
    EEPROM.write(address++, *p++);
  }
}

int EEPROM_ReadInt(int address)
{
  int value = 0;
  byte* p = (byte*)(void*) &value;
  for(int i = 0; i < sizeof(value); i++)
  {
    *p++ = EEPROM.read(address++);
  }

  return value;
}

byte EEPROM_Read(int address)
{
  byte b = EEPROM.read(address);
  return b;
}

void EEPROM_Write(int address, byte val)
{
  EEPROM.write(address, val);
}

