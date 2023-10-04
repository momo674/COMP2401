#include <stdio.h>

int main() {
    int x, y, z;

    x = 4;
    y= x;

    z = y + 2 * x -3;
    printf ("%d %d %d \n", x, y ,z);
    //2 * x - >  + y -> -3 du

    if (x == y) {
    printf("equal\n");
    }

    else {
    printf("not equal \n");
    }
    return 0;
}


//review ? operator, missed in lecture
//i++ returns the original i
////++i returns the new i
