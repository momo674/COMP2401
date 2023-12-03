#include <stdio.h>

void foo(int x);


int x = 25;

int main()
{
  printf("\n");

  x += 10;
  printf("main:   x = %d\n", x);

  int x = 55;
  x += 10;
  printf("main:   x = %d\n", x);

  {
    int x = 85;
    x += 10;
    printf("inner:  x = %d\n", x);
  }

  printf("main:   x = %d\n", x);

  foo(x);

  printf("main:   x = %d\n", x);
  printf("\n");

  return 0;
} 
