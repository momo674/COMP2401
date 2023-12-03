#include <stdio.h>
#include <string.h>

#include "defs.h"

int main()
{
  ArrayType origArr;
  ArrayType shuffArr;
  int num, rc;

  initArray(&origArr);
  initArray(&shuffArr);

  printf("Number of elements: ");
  scanf("%d", &num);

  rc = fillArray(&origArr, num);
  if (rc < 0) {
    printf("ERROR:  Could not fill array\n");
    return(1);
  }

  shuffleArray(&origArr, &shuffArr);

  printf("\nORIGINAL:  ");
  printArray(&origArr);
  printf("\nSHUFFLED:  ");
  printArray(&shuffArr);
  printf("\n");

  return 0;
}

void shuffleArray(ArrayType *orig, ArrayType *shuff)
{
  for (int i=0; i<orig->size; ++i) {
    addToArray(shuff, orig->elements[i]);
  }
}

int fillArray(ArrayType *arr, int numElements)
{
  if (numElements <= 1 || numElements > MAX_SIZE) {
    arr->size = 0;
    return C_NOK;
  }

  arr->elements[0] = 0;
  arr->elements[1] = 1;

  for (int i=2; i<numElements; ++i) 
    arr->elements[i] = arr->elements[i-1] + arr->elements[i-2];

  arr->size = numElements;
  return C_OK;
}

