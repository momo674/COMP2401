//no idea what was going on.

#include <stdio.h>
#include <string.h>

#define MAX_STR1 16
#define MAX_STR2 64

int main() {
    int year = 2023;

    char inStr1[MAX_STR1];
    char inStr2[MAX_STR1];
    char newStr[MAX_STR1];  
    char bigStr[MAX_STR2];

    printf("Please enter two strings: ");
    scanf("%s %s", inStr1, inStr2);
    printf("You said: %s %s\n, inStr1, inStr2");

    printf("\nString Lengths: %ld %ld\n\n", strlen(inStr1),strlen(inStr2));

    strcpy(newStr, inStr1);

    newStr[0] = 'J';
    printf("I say: %s %s\n", inStr1, newStr);

    printf("We botjh say: %s %s\n", strcat(inStr1, newStr), inStr2);

}