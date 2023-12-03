#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
  int num, i;
  int highest = 100;
  int lowest  = 0;

  srand( (unsigned)time( NULL ) );

  scanf("%d", &num);
  for (i=0; i<num; i++) {
    int rnd = rand();
    printf("%d\n", (rnd % ((highest - lowest) + 1)) + lowest);
  }
  printf("-1\n");
}
