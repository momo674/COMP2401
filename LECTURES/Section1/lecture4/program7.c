//prompts user to enter value in an array
//computers max numbers entered
#include <stdio.h>
#define MAX_SIZE 16


int getData(int*);
int computeMax(int*, int);


int main() {
    int array[MAX_SIZE];
    int max;
    int currNum;
    int totalNums;
    totalNums = getData(array);
    max = computeMax(array, totalNums);
    printf("Max is %d\n", max);
    return 0;

    
}


int getData(int *arr) {
    int currNum;
    int totalNums = 0;


    //assume array is not properly intizlized, lets do it properly
    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = 0;
    }

    printf("please enter number: ");
    scanf ("%d", &currNum);

    while (totalNums < MAX_SIZE && currNum != -1) {
        arr[totalNums] = currNum;
        ++totalNums; 
        printf("please enter number: ");
        scanf ("%d", &currNum);
    }

    return totalNums;
}

int computeMax(int *arr, int total){
    int max = 0;

    for (int i = 0; i < total; ++i){
        if (arr[i] > max) {
            max = arr[i];
        }
    }

   
    return max;
}

//issues, everything is only in main!