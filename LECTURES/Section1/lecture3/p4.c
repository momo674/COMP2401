#include <stdio.h>

//this is defining (pre processing) variables. its so simple code that we dont need proper syntax.
#define MAX_SIZE 16
#define C_OK 0
#define C_NOK -1

//forward reference, it pre processes function calls so we can have main at the top of our code
void initArray(int*);
int findNum(int*, int);



/*
        C SYMBOLS
    
        - & is used to change a vairbles data.
        - "%d" is a placeholder for data in a string, such as int.
        - * is used to define a variable as an arry (not 100% sure)
        
*/


/*
    REVIEW
    - the new symbols in c
    pre processing
    #define

*/



//main function
int main() {

    //an array of our preprocessed variable MAX_SIZE
    int array[MAX_SIZE];

    //defining integers index and selected number
    int index, selectedNum;

    //calling our function that initializes an array
    initArray(array);


    printf("Please enter the number you want to find: ");

    
    scanf("%d", &selectedNum);

    index = findNum(array, selectedNum);

    if (index >= 0) {
        printf("we found number %d at index %d\n", selectedNum, index);
    }

    else{
        printf("We could not find number %d\n", selectedNum);
    }
    return 0;
}


/*
    Function: finds index of desired number in array.
    Input:Array (arr), desired number (num)
    Output: returns index (int) else returns C_NOK 
*/
int findNum(int *arr, int num) {
    for (int i=0; i < MAX_SIZE; ++i) {
        if (arr[i] == num) {
            return i;
        }

        return C_NOK;
    }
}
/*
    Function: creares an array of fibanochi numbers
    Input: any array
    Output: array of fibanochi numbers
    our parameter is an output parameter because we dont care whats inside.
*/
void initArray (int *arr) {
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <MAX_SIZE; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    for (int i = 0; i <MAX_SIZE; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}