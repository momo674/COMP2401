#include <stdio.h>
#include <stdlib.h>

void doInitBad(int);
void doInitGood(int*);

void doAllocBad(int*);
void doAllocGood(int**);


int main()
{
  int  num;
  int *ptr;

  doInitBad(num);
  printf("%d\n", num);

  doInitGood(&num);
  printf("%d\n", num);

  doAllocBad(ptr);
//  printf("%d\n", *ptr);

  doAllocGood(&ptr);
  printf("%d\n", *ptr);

  return 0;
}

void doAllocGood(int **p)
{
  *p = malloc(sizeof(int));
  **p = 80;
}

void doAllocBad(int *p)
{
  p = malloc(sizeof(int));
  *p = 80;
}

void doInitGood(int *n)
{
  *n = 77;
}

void doInitBad(int n)
{
  n = 77;
}






