/*
*  Arduino Workshop
 * Works_019
*  Memory Management (1)
 */

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
 * space. Dynamic data, also known as heap, starts from top of the SRAM block and
 * accumulates towards bottom. Stack, the local variables, starts from 'top' of the
 * static data, and moves upwards. This means, when stack and heap meets each other,
 * this causes stack overflow within the SRAM and causes program to stop execute.
 * 
 * Also note, if heap memory frees itself over time, there is a case where freed memory
 * space is within heap. If heap memory is managed badly(ie. memory is freed somewhere
 * inbetween allocated heap spaces), this will case 'fragment' within heap memory,
 * causing fragmentation. You can still 'use' these fragmented spaces, but it will be
 * hard to allocate any dynamic memory bigger than fragmented spaces.
 * 
 * EEPROM stands for Electronically Erasable, Programmable, Read-Only-Memory. Inside
 * of ATmega chip, it has built-in EEPROM space (not too many, but enough to store
 * pre-determined data) which can be store as byte data. While READING from EEPROM is
 * unlimited, WRITING to EEPROM is limited to 100,000 cycles.
 * 
 * During this session, we will look into how to check available memory in SRAM. Note
 * that the only memory we can control manually is EEPROM. So we can only check available
 * SRAM through ATmega chip.
 * 
 * This example shows how variable size affects SRAM.
 */

/* Variables */
static long val = 0;
int lastRAM;
String line = "Total: ";

void setup()
{
  Serial.begin(115200);
  lastRAM = getSRAM();
}

void loop()
{
  line = "Total: ";
  val += 10;
  int currRAM = getSRAM();
  line.concat(val);
  if(currRAM != lastRAM)
  {
    Serial.println(line);
    Serial.print("SRAM: "); Serial.println(currRAM);
    lastRAM = currRAM;
  }
  delay(1);
}

/*
 * __brkval is the highest point of allocated heap memory.
 * __heap_start is the starting point of allocated heap memory.
 * 
 * Function creates single integer variable, which will be created
 * on top of the stack. Then we simply subract spaces between
 * newly created integer variable to top of the heap, giving us
 * available SRAM space in the end.
 */
int getSRAM()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

