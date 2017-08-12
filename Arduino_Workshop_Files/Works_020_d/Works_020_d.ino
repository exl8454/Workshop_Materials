/*
*  Arduino Workshop
 * Works_020_d
*  Memory Management (4)
 */

 /*
 * The 'bad' heap memory allocation.
 * (Not really bad, but to show the phenomenon of pushing the memory to edge)
  */

/* Variables */
long heap_size = 1;
long count = 0;
long *heap_long, *heap_temp;

void setup()
{
  /* For displaying data */
  Serial.begin(115200);
  Serial.println("**********The Cursed Dynamic Allocation**********");

  heap_long = malloc(heap_size * sizeof(long));

  /* Print how much SRAM we have at the beginning */
  Serial.print("Initial SRAM Space: ");
  Serial.println(getSRAM());
  Serial.println();
}

void loop()
{
  /*
   * Each time when user hits enter (ie. sends newline delimiter to Arduino),
   * counter is added. Whenever counter exceeds maximum heap size, heap size will
   * be doubbled, then tries to reallocate the heap with given new heap size.
   */
  while(!Serial.available())
    ;
  if(count >= heap_size)
  {
    heap_size *= 2;
    heap_temp = realloc(heap_long, heap_size * sizeof(long));
    if(heap_temp != NULL)
    {
      heap_long = heap_temp;
      Serial.print("New heap size: "); Serial.println(heap_size);
    }
    else
      Serial.println("Cannot allocate no more!");
  }
  heap_long[count] = count;
  Serial.print("heap_long["); Serial.print(count); Serial.print("]: ");
  Serial.println(heap_long[count]);

  Serial.print("SRAM Space: "); Serial.println(getSRAM());
  Serial.println();

  count++;

  while(Serial.available())
    Serial.read();
}

int getSRAM()
{
  extern int __heap_start, *__brkval;
  int v;

  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

