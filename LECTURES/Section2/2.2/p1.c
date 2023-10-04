#include <stdio.h>

int main() {
    int a[4];
    float b[3];
    char c[10];
    int i;

    printf("\n");

    printf("%d %f %d\n", a[0], b[5], c[3]); // -> expecting garbage. i got lucky and got all 0.
    //%lu means %long and u means unsigned
    printf("size of a: %lu\n\n", sizeof(a)); // -> expecting 16?
    printf("size of c: %lu\n", sizeof(c)); // -> expecting 10?
    //sizeof return the number of bytes.
    //1 int = 4 bytes
    //1 char = 1 byte
    //arr[2][3][4] sizeof == 2 x 3 x 4 = 24 x 4 = 96

    int arr[2][3][4] = 
    {
        {
           {1,2,3,4},
           {5,6,7,8},
           {9,10,11,12} 
        },

        {
            {13,14,15,16},
            {17,18,19,20},
            {21,22,23,24}
        }
    };

printf("%d", sizeof(arr)); //-> 96 ???
    for (i = 0; i <sizeof(c); i++) {
        printf("%d", c[i]); //prints garbage
    } 
    printf("\n");
}