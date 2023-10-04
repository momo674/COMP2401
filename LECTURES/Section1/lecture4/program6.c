//prompts user to enter value in an array
//computers max numbers entered
#include <stdio.h>
#define MAX_SIZE 16


void getData(int*);
void computeMax(int*, int);


int main() {
    int array[MAX_SIZE];
    int max;
    int currNum;
    int totalNums = 0;

    getData(array);
    

    
}


void getData(int *arr) {
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

    computeMax(arr, totalNums);
}

void computeMax(int *arr, int total){
    int max = 0;

    for (int i = 0; i < total; ++i){
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Max is %d\n", max);
    
}

//issues, everything is only in main!