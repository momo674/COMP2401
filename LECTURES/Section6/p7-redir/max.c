#include <stdio.h>

#define MAX_NUMS 100

int main()
{
  int arr[MAX_NUMS];
  int num, currMax, i; 
  int count = 0;

  while (1) {
    scanf("%d", &num);
    if (num < 0)
      break;
    arr[count++] = num;
  }

  currMax = 0;

  for (i=0; i<count; i++) {
    if (arr[i] > currMax)
      currMax = arr[i];
  }
  
  printf("max is %d\n", currMax);

}
