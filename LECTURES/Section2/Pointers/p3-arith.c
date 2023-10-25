#include <stdio.h>
#include <string.h>


int main()
{
  char charArr[32];
  int  intArr[8];
  int  *ptr;


  strcpy(charArr, "Timmy Tortoise");

  for (int i=0; i<8; ++i) {
    intArr[i] = (i+1) * 2;
    printf("%d ", intArr[i]);
  }

  printf("\n");

  printf("First int:   %d\n", *intArr);
  printf("Fourth int:  %d\n", *(intArr + 3)); // intArr[3]
  printf("\n");

  *(charArr + 2) = 'p';
  *(charArr + 3) = 'p';
  printf("New string: %s\n", charArr);

//  printf("Part string: %s\n", &(charArr[6]));
  printf("Part string: %s\n", charArr + 6);

  ptr = intArr + 6;

  printf("Seventh int:  %d\n", *ptr);
  printf("Eight int:    %d\n", ptr[1]);
  printf("Fifth int:    %d\n", *(ptr - 2));


  return 0;
}
