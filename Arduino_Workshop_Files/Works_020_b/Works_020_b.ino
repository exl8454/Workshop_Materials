/*
*  Arduino Workshop
 * Works_020_b
*  Memory Management (2)
 */

/*
*  Stack Memory
 * This will show how stack memories can cause stack overflow.
*/

static unsigned long val = 0;

void f(unsigned long n)
{
  Serial.print("SRAM Space: "); Serial.println(getSRAM());
  f1(n + 100);
}

void f1(unsigned long n)
{
  Serial.print("SRAM Space: "); Serial.println(getSRAM());
  f2(n + 100);
}

void f2(unsigned long n)
{
  Serial.print("SRAM Space: "); Serial.println(getSRAM());
  f3(n + 100);
}

void f3(unsigned long n)
{
  Serial.print("SRAM Space: "); Serial.println(getSRAM());
  f(n + 100);
}

void setup()
{
  /* For displaying data */
  Serial.begin(115200);
  Serial.println("**********STACK AND STACK ALLOCATION**********");

  /* Print how much SRAM we have at the beginning */
  Serial.print("Initial SRAM Space: ");
  Serial.println(getSRAM());
  Serial.println();
}

void loop()
{
  /*
  *  For Stack, we cannot manipulate how stack memory is controlled.
   * However, we can 'create' something to cause stack overflow.
  */
  Serial.print("SRAM Space: "); Serial.println(getSRAM());
  f(val);
  /*
   * But apparently, we notice SRAM still remains the same. Why?
   * This is because Arduino actually handles garbage collection abit.
   * That is, Arduino will handle the stack memory to its best to
   * keep sufficient memory.
  */
}

int getSRAM()
{
  extern int __heap_start, *__brkval;
  int v;

  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

