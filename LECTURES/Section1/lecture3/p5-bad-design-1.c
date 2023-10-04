//prompts user to enter value in an array
//computers max numbers entered
#include <stdio.h>
#define MAX_SIZE 16

int main() {
    int array[MAX_SIZE];
    int max;
    int currNum;
    int totalNums = 0;


    //assume array is not properly intizlized, lets do it properly
    for (int i = 0; i < MAX_SIZE; ++i) {
        array[i] = 0;
    }

    printf("please enter number: ");
    scanf ("%d", &currNum);

    while (totalNums < MAX_SIZE && currNum != -1) {
        array[totalNums] = currNum;
        ++totalNums; 
        printf("please enter number: ");
        scanf ("%d", &currNum);
    }

    max = 0;

    for (int i = 0; i < totalNums; ++i){
        if (array[i] > max) {
            max = array[i];
        }
    }

    printf("Max is %d\n", max);
    return 0;
}

//issues, everything is only in main!