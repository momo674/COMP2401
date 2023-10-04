#include <stdio.h>

int main() 
{
    unsigned char dec = 27; //-> 27
    unsigned char oct  = 027; // -> 23
    unsigned char hex = 0xbf; // ->191
    unsigned char bin = 0b00111100; // ->  60

    //uppercase letters are ok to be used in hexadecimal!
    /*for bin variable, we could store it as 0b111100 and 
    it would still print as 60 since c is smart and it pads it on the left.*/
    printf("%d %d %d %d\n", dec, oct, hex, bin);
}