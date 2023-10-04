#include <stdio.h>

int main () 
{
    printf("\n");
    char myStr[10];
    //myStr = "Hello"; is a huge error!

    myStr[0] = 'J';
    myStr[1] = 'e';
    myStr[2] = 'l';
    myStr[3] = 'l';
    myStr[4] = 'o';
    myStr[5] = '\0'; 

    printf("myStr as a string: %s\n", myStr); //prints as string
    printf("myStr as a int: %d\n", myStr); //prints address
    printf("myStr as a char: %c\n", myStr); //takes address and tries to print it as an ascii character, ubuntu prints it as trash symbol?
    
    printf("\n");

    //printf("myStr[0] as a string: %s\n", myStr[0]); //doesnt work, starts at that address?
    printf("myStr[0] as a int: %d\n", myStr[0]); //prints ascii value
    printf("myStr[0] as a char: %c\n", myStr[0]); //prints the actual char

    printf("\n");

    myStr[5] = 'L';
    printf("%s\n", myStr); //itll go on until we hit another null character, we dont know how long it will take

    myStr[4] = '0';
    printf("%s\n", myStr); //just adds the char 0 and still the same issue

    myStr[3] = 0; //same as myStr[3] = '\0'
    printf("%s\n", myStr); //ends the print at inde 3 since it is the null character

    //value 0 is null character, but '\0' is a char of the value 0. just like how '\n' is new line, there is a value behind it. 'J' == 73 i think?

    
    return 0;
}