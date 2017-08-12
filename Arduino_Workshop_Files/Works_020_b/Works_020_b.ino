/*
*  Arduino Workshop
 * Works_020_b
*  Memory Management (3)
 */

/*
*  Heap Memory Management
 * This will show how to allocate and free heap memory space(s).
*/

struct node
{
  int* heap_size;

  char* heap_name;
};

void setup()
{
  /* For displaying data */
  Serial.begin(115200);
  Serial.println("**********HEAP AND DYNAMIC ALLOCATION**********");

  /* Print how much SRAM we have at the beginning */
  Serial.print("Initial SRAM Space: ");
  Serial.println(getSRAM());
  Serial.println();

  /*
  *  Regardless of what type of data type we allocate, we always use
   * -> malloc(size_in_byte);
  *  -> calloc(num_items, single_item_size);
   * -> realloc(initial_pointer, new_size_in_byte);
  *  We will look into each one.
   * 
  * Remember, you can only use allocate functions with pointers ONLY!
   */

  /*
  *  malloc(size_in_byte) is to allocate heap memory, without initialization.
   * This also means you can allocate memory size for an array.
  *  Remember, all functions takes size as BYTE. This means you have to define
   * Memory size as in BYTE (You can use sizeof(data_type) to get size)
  */
  int heap_size = 1;
  int* heap_int = malloc(sizeof(int)); /* This will allocate memory for 1 int*/
  *heap_int = 10;
  Serial.print("heap_int: "); Serial.println(*heap_int);

  Serial.print("SRAM Space after malloc(sizeof(int)): ");
  Serial.println(getSRAM());
  Serial.println();

  /*
  *  realloc(initial_pointer, new_size_in_byte) basically 'reallocates' new memory space
   * and returns its new memory location pointer. If new pointer is fail to allocate,
  *  function returns NULL.
  *  If realloc function fails to find new space, its pointer will set to initial_pointer.
   */

  heap_size *= 2;
  int* temp_int = realloc(heap_int, heap_size * sizeof(int));
  if(temp_int != NULL)
    heap_int = temp_int;
  else
    Serial.println("Could not reallocate new heap size");

  Serial.print("heap_int[1] (before): "); Serial.println(heap_int[1]);
  heap_int[1] = 20;
  Serial.print("heap_int[1] (after): "); Serial.println(heap_int[1]);

  Serial.print("SRAM Space after realloc(): ");
  Serial.println(getSRAM());
  Serial.println();

  /* Dynamic memory allocation! */
  int i = 0;
  for(i = 0; i < 10; i++)
  {
    if(i >= heap_size)
    {
      heap_size *= 2;
      temp_int = realloc(heap_int, heap_size * sizeof(int));
      if(temp_int != NULL)
        heap_int = temp_int;
      else
        Serial.println("Could not reallocate heap_int");

      Serial.print("New heap_int size: "); Serial.println(heap_size);
    }

    heap_int[i] = i;
  }
  Serial.println();

  for(i = 0; i < 10; i++)
  {
    Serial.print("heap_int["); Serial.print(i); Serial.print("]: ");
    Serial.println(heap_int[i]);
  }

  Serial.print("SRAM Space: ");
  Serial.println(getSRAM());
  Serial.println();

  /* To free heap space, simply use free(pointer) function! */
  free(heap_int);

  Serial.print("SRAM Space after free(heap_int): ");
  Serial.println(getSRAM());
  Serial.println();

  /* 
  *  calloc(num_items, size_in_byte) allocates heap space, but it also initializes
   * allocated memory space with zeros.
  * 
   * Usually, calloc is ideal for single data type, which means it might cause
  *  problem with strings(ie. array of char) since every space is filled with zeros.
   */
  heap_size = 10;
  heap_int = calloc(heap_size, sizeof(int));

  for(i = 0; i < 10; i++)
  {
    Serial.print("heap_int["); Serial.print(i); Serial.print("]:");
    Serial.println(heap_int[i]);
  }
  
  for(i = 0; i < 10; i++)
  {
    if(i >= heap_size)
    {
      heap_size *= 2;
      temp_int = realloc(heap_int, heap_size * sizeof(int));
      if(temp_int != NULL)
        heap_int = temp_int;
      else
        Serial.println("Could not reallocate heap_int");

      Serial.print("New heap_int size: "); Serial.println(heap_size);
    }

    heap_int[i] = i;
  }
  Serial.println();

  for(i = 0; i < 10; i++)
  {
    Serial.print("heap_int["); Serial.print(i); Serial.print("]:");
    Serial.println(heap_int[i]);
  }

  Serial.print("SRAM Space: ");
  Serial.println(getSRAM());
  Serial.println();

  free(heap_int);

  Serial.print("SRAM Space after free(heap_int): ");
  Serial.println(getSRAM());
  Serial.println();

  /*
  *  To allocate matrix, simply make pointer twice.
   * Imagine first pointer as ROW and second pointer as COLUMN.
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
      Serial.print(heap_matrix_float[i][j]); Serial.print(" ");
    }
    Serial.println();
  }

  Serial.print("SRAM Space after 2 x 10 float Matrix: ");
  Serial.println(getSRAM());
  Serial.println();

  /* If you allocated matrix to heap, make sure you free from inside-out! */
  for(i = 0; i < 2; i++)
  {
    /* free(heap_matrix_float); Don't do this! */
    free(heap_matrix_float[i]); /* This will free single row */
    /* We don't need to free each element since it was allocated while we were 
       allocating single row. When you free one row, you are freeing elements within
       that row.
    */
  }
  free(heap_matrix_float);
  heap_matrix_float = NULL;

  Serial.print("SRAM Space after free 2 x 10 float Matrix: ");
  Serial.println(getSRAM());
  Serial.println();

  /* 
  *  Let's try allocating single string to heap.
   * We know string in C is composition(array) of characters in array.
  *  And array always points at first index, index zero. This means,
   * since memory allocation functions returns memory pointer of allocated
  *  memory, if we allocate memory size enough to store any given char array,
   * we have dynamically allocated memory for single string.
  */
  char stack_string[37] = "This is a string allocated to stack\n";
  char *heap_string;

  /* 
  *  When allocating a string, remember don't forget to add one extra space. This is
   * because when allocating string, this does not include null terminator(\0) at the
  *  end automatically.
   */
  heap_string = malloc( (strlen(stack_string) + 1) * sizeof(char) );
  /* Use strcpy(dest, source) to copy strings */
  strcpy(heap_string, stack_string);

  Serial.print("stack_string: "); Serial.print(stack_string);
  Serial.print("heap_string: "); Serial.print(heap_string);

  Serial.print("SRAM Space after allocating heap_string: ");
  Serial.println(getSRAM());
  Serial.println();

  /* 
  *  One good thing about dynamic allocation, you can have arrays of various size
   * within matrix!
  */
  char stack_line_1[28] = "This is first line: FOOBAR\n";
  char stack_line_2[26] = "This is second line: FOO\n";
  char stack_line_3[22] = "This is third line: \n";
  char** heap_lines;
  heap_lines = malloc( 3 * sizeof(char*) );
  
  heap_lines[0] = malloc( (strlen(stack_line_1) + 1) * sizeof(char) );
  strcpy(heap_lines[0], stack_line_1);
  heap_lines[1] = malloc( (strlen(stack_line_2) + 1) * sizeof(char) );
  strcpy(heap_lines[1], stack_line_2);
  heap_lines[2] = malloc( (strlen(stack_line_3) + 1) * sizeof(char) );
  strcpy(heap_lines[2], stack_line_3);

  Serial.print(heap_lines[0]);
  Serial.print(heap_lines[1]);
  Serial.print(heap_lines[2]);

  Serial.print("SRAM Space after allocating string with 3 lines: ");
  Serial.println(getSRAM());
  Serial.println();

  /*
  *  Notice I have not yet freed first heap_string.
   * Let's see what happens when we free the
  *  first string before 3 lines.
  *  (Comment out after demonstration)
  */
//  free(heap_string);
//  Serial.print("SRAM Space after free(heap_string): ");
//  Serial.println(getSRAM());
//  Serial.println();

  /*
  *  Notice how memory spaces changes; it stays the same. This is because we actually
   * 'freed' heap from memory space, but controller cannot 'reach' to that memory gap.
  *  It is impossible to allocate something bigger than freed memory NOW since we
   * cannot simply shift fragmented memory spaces around. Remember, memories work 
  *  based on addresses; us assigning variables means that variable will occupy 
   * certain memory space, denoted by memory address.
  *
   * Question remains; how do we avoid memory fragmentation? It is simple; LIFO.
  *  LIFO stands for Last In, First Out. Any heap memory allocated at very last should
   * be freed first. This means, above example, 3 line strings should have freed BEFORE
  *  we free single-line string.
   */
  for(i = 2; i >= 0; i--)
  {
    free(heap_lines[i]);
  }
  /*
  *  Since we assigned index 2 at very last, we start w/ index 2. However, order doesn't
   * matter that much. We are doing this just to show proper LIFO order.
  */
  free(heap_lines);
  free(heap_string);

  Serial.print("SRAM Space after free-ing all strings: ");
  Serial.println(getSRAM());
  Serial.println();

  /* Yes, you can assign structures to heap as well! */
  char aName[] = "John";
  struct node* heap_node = malloc( sizeof(struct node) );
  heap_size = 2;

  /*
  *  When you allocate heap space for structures, variables inside structures are not
   * initialized.
  */
  heap_node->heap_name = calloc((strlen(aName) + 1), sizeof(char));
  strcpy(heap_node->heap_name, aName);
  Serial.print("heap_name: "); Serial.println(heap_node->heap_name);
  
  Serial.print("SRAM Space after heap_name: ");
  Serial.println(getSRAM());
  Serial.println();

  heap_node->heap_size = malloc(heap_size * sizeof(int));
  heap_node->heap_size[0] = 10;
  for(i = 0; i < 20; i++)
  {
    if(i >= heap_size)
    {
      heap_size *= 2;
      temp_int = realloc(heap_node->heap_size, heap_size * sizeof(int));
      if(temp_int != NULL)
      {
        heap_node->heap_size = temp_int;
        Serial.print("New heap size: "); Serial.println(heap_size);
      }
      else
        Serial.println("Fail to reallocate new size");
    }
    heap_node->heap_size[i] = (i + 1) * 10;
  }
  Serial.println();

  for(i = 0; i < 20; i++)
  {
    Serial.print("heap_size["); Serial.print(i); Serial.print("]: ");
    Serial.println(heap_node->heap_size[i]);
  }
  
  Serial.print("SRAM Space after heap_size: ");
  Serial.println(getSRAM());
  Serial.println();

  /* To free the structure's memory, just like matrix, start with inside, then go outward */
  free(heap_node->heap_size);
  free(heap_node->heap_name);
  free(heap_node);
  
  Serial.print("SRAM Space after releasing structure: ");
  Serial.println(getSRAM());

  /* Other ways to compact memory size is by free, malloc and realloc.
   *  What this mean is that 
  */
}

void loop()
{
}

int getSRAM()
{
  extern int __heap_start, *__brkval;
  char v;

  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

