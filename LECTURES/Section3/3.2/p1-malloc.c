#include <stdio.h>
#include <stdlib.h>

int main()
{
  int numInts = 5;
  int *ptr;

  ptr = malloc(numInts * sizeof(int));
  /*

    how could we use calloc?
    1. ptr = calloc(numInts, sizeof(int))
    now our ptr doesnt point to garbage, it points to null;
  */

  // ptr = calloc(numInts, sizeof(int)); --> blocks of NULL (%d == 0)

  // printf("%d %c\n", ptr[4],ptr[0]);



  ptr[0] = 10;
  ptr[1] = 20;
  ptr[2] = 30;
  *(ptr+3) = 40;
  *(ptr+4) = 50;

  printf("\n");

  for (int i=0; i<numInts; ++i) {
    printf("%d ", ptr[i]);
  }
  printf("\n");


  return 0;
}

