#include <stdio.h>
#include "myDefinitions.h"
int main() {
 int x = MAX;
 int *y = &x;

#ifdef DEBUG
    printf("DEBUG\n");
#endif

 printf("x + *y = %d\n", x + *y);
 printf("Days = %d, PI = %f\n", DAYS_OF_WEEK, PI);
}
