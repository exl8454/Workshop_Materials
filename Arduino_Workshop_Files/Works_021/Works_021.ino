// Arduino Workshop
// Works_021
// Memory Management (3)

/**
 * Some other ways to save memory through arduino...
 */

String sram = "SRAM: ";
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  sram = "SRAM: ";
  sram.concat(getSRAM());
  Serial.print(sram);
  /**
   * F() function allows strings to called from FLASH memory directly, instead
   * of copying string literals to SRAM then print. Remember this function cannot
   * be used on any variable strings
   */
  Serial.print(F(" SRAM: ")); Serial.println(getSRAM());

  delay(1000);
}

int getSRAM()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
