#include "defs.h"

void addToArray(ArrayType *arr, int num)
{
  static int parity = 0;

  if (arr->size >= MAX_SIZE)
    return;

  if (parity % 2 == 0) {
    addFront(arr, num);
  }
  else {
    addBack(arr, num);
  }

  ++parity;
}

void addFront(ArrayType *arr, int num)
{
  if (arr->size >= MAX_SIZE)
    return;

  for (int i=arr->size; i>0; --i)
    arr->elements[i] = arr->elements[i-1];

  arr->elements[0] = num;
  ++arr->size;
}

void addBack(ArrayType *arr, int num)
{
  if (arr->size >= MAX_SIZE)
    return;

  arr->elements[arr->size] = num;
  ++arr->size;
}

void initArray(ArrayType *arr)
{
  arr->size = 0;
}

void printArray(ArrayType *arr)
{
  for (int i=0; i<arr->size; ++i) {
    printf("%d ", arr->elements[i]);
  }
  printf("\n");
}

