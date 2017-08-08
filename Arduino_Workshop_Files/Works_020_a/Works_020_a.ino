/*
*  Arduino Workshop
 * Works_020
*  Memory Management (2)
 */

/*
*  Heap Memory Management
 * This will show how to allocate and free heap memory space(s).
*/

struct node
{
  char *node_name;
  int *node_size;
};

void setup()
{
  /* For displaying data */
  Serial.begin(115200);

  /* Print how much SRAM we have at the beginning */
  Serial.print("Initial SRAM Space: ");
  Serial.println(getSRAM());

  /* Regardless of what type of data type we allocate, we always use   */
  /* -> malloc(size_in_byte);                                          */
  /* -> calloc(size, data_type_size);                                  */
  /* -> realloc(initial_pointer, new_size_in_byte);                    */
  /* We will look into each one.                                       */
  /* Remember, you can only use allocate functions with pointers ONLY! */

  /* malloc(size_in_byte) is to allocate heap memory, without initialization.*/
  /* This also means you can allocate memory size for an array. */
  /*
  *  Remember, all functions takes size as BYTE. This means you have to define
   * Memory size as in BYTE (You can use sizeof(data_type) to get size)
  */
  int heap_size = 1;
  int* heap_int = malloc(heap_size * sizeof(int)); /* This will allocate memory for 1 int*/
  heap_int[0] = 0;
  Serial.print("heap_int[0]"); Serial.println(heap_int[0]);

  Serial.print("SRAM Space: ");
  Serial.println(getSRAM());

  /*
  *  realloc(initial_pointer, new_size_in_byte) basically 'reallocates' new memory space
   * and returns its new memory location pointer. If new pointer is fail to allocate,
  *  function returns NULL.
   */

  heap_size *= 2;
  int* temp_int = realloc(heap_int, heap_size * sizeof(int));
  if(temp_int != NULL)
    heap_int = temp_int;
  else
    Serial.println("Could not reallocate new heap size");

  heap_int[1] = 1;
  Serial.print("heap_int[1]"); Serial.println(heap_int[1]);

  Serial.print("SRAM Space: ");
  Serial.println(getSRAM());

  /* Dynamic memory allocation! */
  int i = 0;
  for(i = 0; i < 10; i++)
  {
    if(i >= heap_size)
    {
      heap_size *= 2;
      temp_int = realloc(heap_size, sizeof(int));
      if(temp_int != NULL)
        heap_int = temp_int;
      else
        Serial.println("Could not reallocate heap_int");

      Serial.print("New heap_int size: "); Serial.println(heap_size);
      Serial.print("SRAM Space: "); Serial.println(getSRAM());
    }

    heap_int[i] = i;
  }

  for(i = 0; i < 10; i++)
  {
    Serial.print("heap_int["); Serial.print(i); Serial.print("]:");
    Serial.println(heap_int[i]);
  }

  Serial.print("SRAM Space: ");
  Serial.println(getSRAM());

  /* To free heap space, simply use free(pointer) function! */
  free(heap_int);

  Serial.print("SRAM Space after free(heap_int): ");
  Serial.println(getSRAM());

  /* 
  *  calloc(size, single_data_size) allocates heap space, but it also initializes
   * allocated memory space with zeros.
   * 
   * Usually, calloc is ideal for single data type, which means it might cause
   * problem with strings(ie. array of char) since every space is filled with zeros.
  */

  heap_size = 1;
  heap_int = calloc(heap_size, sizeof(int));

  Serial.print("heap_int[0] with calloc: "); Serial.println(heap_int[0]);\
  for(i = 0; i < 10; i++)
  {
    if(i >= heap_size)
    {
      heap_size *= 2;
      temp_int = realloc(heap_size, sizeof(int));
      if(temp_int != NULL)
        heap_int = temp_int;
      else
        Serial.println("Could not reallocate heap_int");

      Serial.print("New heap_int size: "); Serial.println(heap_size);
      Serial.print("SRAM Space: "); Serial.println(getSRAM());
    }

    heap_int[i] = i;
  }

  for(i = 0; i < 10; i++)
  {
    Serial.print("heap_int["); Serial.print(i); Serial.print("]:");
    Serial.println(heap_int[i]);
  }

  Serial.print("SRAM Space: ");
  Serial.println(getSRAM());

  free(heap_int);

  Serial.print("SRAM Space after free(heap_int): ");
  Serial.println(getSRAM());

  /*
  *  To allocate matrix, simply make pointer twice.
   * Simply imagine first pointer as ROW and second pointer as COLUMN.
  *  Which means, you will need to allocate ROW first, then COLUMN.
   */
  int j;
  float** heap_matrix_float;

  /*
  *  Remember, you are allocating ROW first, so your size will be size of
   * array, which we have not yet allocated.
  */
  heap_matrix_float = malloc(2 * sizeof(float*)); /* Rows of 2! */

  j = 10; /* We will make column size of 10. */
  for(i = 0;i < 2; i++)
  {
    heap_matrix_float[i] = malloc(j * sizeof(float));
  }

  for(i = 0; i < 2; i++)
    for(j = 0; j < 10; j++)
    {
      heap_matrix_float[i][j] = i + j;
    }

  for(i = 0; i < 2; i++)
  {
    for(j = 0; j < 10; j++)
    {
      Serial.print(i); Serial.print(" ");
    }
    Serial.println();
  }

  Serial.print("SRAM Space after 2 x 10 float Matrix: ");
  Serial.println(getSRAM());

  /* If you allocated matrix to heap, make sure you free from inside->out! */
  for(i = 0; i < 2; i++)
  {
    free(heap_matrix_float[i]); /* This will free single row */
    /* We don't need to free each element since it was allocated while we were 
       allocating single row. When you free one row, you are freeing elements within
       that row.
    */
  }

  Serial.print("SRAM Space after free 2 x 10 float Matrix: ");
  Serial.println(getSRAM());

  /* Let's try allocating single string to heap */
  char stack_string[100] = "This is a string allocated to stack";
  char *heap_string;

  /* 
  *  When allocating a string, remember don't forget to add one extra space. This is
   * because when allocating string, this does not include null terminator(\0) at the
  *  end automatically.
   */
  heap_string = malloc( (strlen(stack_string) + 1) * sizeof(char) );
  /* Use strcpy(dest, source) to copy strings */
  strcpy(heap_string, stack_string);

  Serial.print("stack_string: "); Serial.println(stack_string);
  Serial.print("heap_string: "); Serial.println(heap_string);

  Serial.print("SRAM Space after allocating heap_string: ");
  Serial.println(getSRAM());

  /* 
  *  One good thing about dynamic allocation, you can have arrays of various size
   * within matrix!
  */
  char stack_line_1[26] = "This is first line: FOOBAR";
  char stack_line_2[24] = "This is second line: FOO";
  char stack_line_3[20] = "This is third line: ";
  char** heap_lines;
  heap_lines = malloc( 3 * sizeof(char*) );
  
  heap_lines[0] = malloc( (strlen(stack_line_1) + 1) * sizeof(char) );
  strcpy(heap_lines[0], stack_line_1);
  heap_lines[1] = malloc( (strlen(stack_line_2) + 1) * sizeof(char) );
  strcpy(heap_lines[1], stack_line_2);
  heap_lines[2] = malloc( (strlen(stack_line_3) + 1) * sizeof(char) );
  strcpy(heap_lines[2], stack_line_3);

  Serial.println(heap_lines[0]);
  Serial.println(heap_lines[1]);
  Serial.println(heap_lines[2]);

  Serial.print("SRAM Space after allocating string with 3 lines: ");
  Serial.println(getSRAM());

  /*
  *  Notice I have not yet freed first string. Let's see what happens when we free the
   * first string.
  */
  free(heap_string);
  Serial.print("SRAM Space after free(heap_string): ");
  Serial.println(getSRAM());

  /*
  *  Notice how memory spaces changes; rather it stays the same or it actually shows 
   * changed SRAM size. This is because we actually 'freed' heap from memory space.
  *  However, it is impossible to allocate something bigger than freed memory since
   * we cannot simply shift fragmented memory spaces around. Remember, memories work 
  *  based on addresses; us assigning variables means that variable will occupy 
   * certain memory space, denoted by memory address.
  */

  /*
  *  Question remains; how do we avoid memory fragmentation? It is simple; LIFO.
   * LIFO stands for Last In, First Out. Any heap memory allocated at very last should
  *  be freed first. This means, above example, 3 line strings should have freed BEFORE
   * we free single-line string.
  */
  for(i = 2; i >= 0; i--) /* Since we assigned index 2 at very last, we start w/ index 2*/
  {
    free(heap_lines[i]);
  }
  free(heap_string);

  Serial.print("SRAM Space after free-ing all strings: ");
  Serial.println(getSRAM());

  /* Yes, you can assign structures to heap as well! */
  struct node* heap_node = malloc( sizeof(struct node) );

  /*
  *  When you allocate heap space for structures, variables inside structures does not
  *  initialized, unless it is variable assigned in stack memory.
  */
}

void loop()
{
}

int getSRAM()
{
  extern int __heap_start, *__brkval;
  int v;

  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

