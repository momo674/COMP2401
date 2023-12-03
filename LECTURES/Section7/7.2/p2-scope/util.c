#include <stdio.h>

extern int x;

void foo(int z)
{
  x += 10;
  printf("foo:    x = %d\n", x);
} 
