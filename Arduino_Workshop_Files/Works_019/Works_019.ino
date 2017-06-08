// Arduino Workshop
// Works_019
// Memory Management (1)

/**
 * Three different types of memory exists in Arduino; FLASH, SRAM, and EEPROM.
 * FLASH memory is used to store program data, along with bootloader. We cannot
 * edit data inside FLASH memory. To do so, data must be copied to SRAM first.
 * FLASH is non-volatile memory, just like SD card and memory stick. Though you
 * can read FLASH memory without any limit, writing has its limit up to 100,000
 * cycles.
 * 
 * SRAM stands for Static Random Access Memory. This memory cannot be access
 * directly via program. However, you can check available space with simple code.
 * SRAM is where all the variables are stored. This includes static data, local
 * variable, and dynamic items. Static data is stored at the 'bottom' of the SRAM
 * space. dynamic data, also known as heap, starts from top of the static data and
 * accumulates towards top. Stack, the local variables, starts from 'top' of the SRAM
 * space, and moves downwards. This means, when stack and heap meets each other,
 * this causes stack overflow within the SRAM and causes program to stop execute.
 * 
 * EEPROM stands for Electronically Erasable Programmable Read-Only-Memory. Inside
 * of ATmega chip, it has built-in EEPROM space (not to many, but enough to store
 * pre-determined data) which can be store as byte data. While READING from EEPROM is
 * unlimited, WRITING to EEPROM is limited to 100,000 cycles.
 * 
 * During this session, we will look into how to check available memory in SRAM. Note
 * that the only memory we can control manually is EEPROM. So we can only check available
 * SRAM through ATmega chip.
 * 
 * This example shows how variable size affects SRAM.
 */

// Variables
long val = 0;
String line = "Total: ";

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  line = "Total: ";
  val++;
  line.concat(val);
  Serial.println(line);
  Serial.print("SRAM: "); Serial.println(getSRAM());
  delay(1000);
}

int getSRAM()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

