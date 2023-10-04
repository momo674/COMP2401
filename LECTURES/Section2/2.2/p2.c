#include <stdio.h>

int main () 
{
    printf("\n");
    char myStr[10];
    //myStr = "Hello"; is a huge error!

    myStr[0] = 'H';
    myStr[1] = 'e';
    myStr[2] = 'l';
    myStr[3] = 'l';
    myStr[4] = 'o';
    myStr[5] = '\0'; //NULL character, every string must have this \0 at the end of its array of char, or else it would not work.
    
    /*printf expects a /0 so it can be terminated, 
    it will print everything in memory until it hits NULL character*/
    for (int i = 0; i < 5; i++) {
        printf("%c", myStr[i]);
    }
    printf("\n");
    

}