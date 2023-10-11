#include <stdio.h>

int main () {
    char c = 'H';
    int i = 4;
    char *cptr;

    printf("\n");

    printf("Sizes\n");


    cptr = &c;

    printf("addresses: %p %p %p\n", &c, &i, &cptr);


    printf("two ways to print c: %c %c\n", c, *cptr);

    *cptr = 'J';

    printf("two ways to print c: %c %c\n", c, *cptr);

    c = 'L';

    printf("two ways to print c: %c %c\n", c, *cptr);
    // IF WE CHANGE THE VALUE OF POINTER, IT WIL LCHANGE VALUE OF VARIABLE IT IS POITNING TO
    //IF WE CHANGE THE VALUE OF VARIABLE, IT'S POINTER WILL ALSO BE CHANGED TOO
    //we can have multiple pointers pointing to the same variable


}