#include <stdio.h>
#include <stdlib.h>

void doAlloc(int**);


int main()
{
  int numInts = 2;
  int *ptr, *ptr2;

  ptr = malloc(numInts * sizeof(int));

  *ptr   = 10;
  ptr[1] = 20;

  printf("\n%d\n", *ptr);

  free(ptr);

  doAlloc(&ptr2);
  printf("\n%d\n", *ptr2);

  free(ptr2);

  return 0;
}

void doAlloc(int **p)
{
  *p = malloc(sizeof(int));

  **p = 80;
}

