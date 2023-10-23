#include <stdio.h>

int main()
{
  char c = 'H';
  int  i = 42;

  char *cptr;

  printf("\n");

  printf("sizes:  %lu %lu %lu\n", sizeof(c), sizeof(i), sizeof(cptr));
  printf("\n");

  cptr = &c;

  printf("addresses:   %p %p %p\n", &c, &i, &cptr);
  printf("values:      %c %d %p\n", c, i, cptr);
  printf("\n");

  printf("two ways to c:  %c %c\n", c, *cptr);
  printf("\n");

  *cptr = 'J';

  printf("two ways to c:  %c %c\n", c, *cptr);
  printf("\n");

  return(0);
}

