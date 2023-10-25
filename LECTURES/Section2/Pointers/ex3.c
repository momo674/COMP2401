#include <stdio.h>
#include <string.h>


typedef struct {
    int age;
    char name[20];
    char breed[20];
} Bird;

void whoAmI(Bird*);
void pointerCount(int*, int[]);

int main() {

    Bird Franklin;
    Bird* franklinPtr = &Franklin;
    franklinPtr -> age = 5;
    strcpy(franklinPtr->name, "Franklin");
    strcpy(franklinPtr->breed, "Conure");

    whoAmI(franklinPtr);

    int myArray[] = {1,2,3,4,5,6,7,8,9};
    int* myPtr = myArray;
    
    pointerCount(myPtr, myArray);
    printf("***AFTER FUNCTION CALL***\n");
    printf("pointer -> %d   pointer memory -> %d \n", *myPtr, myPtr );

    return 0;
}
//after investigation, it seems that a pointer will always return back to it's original point after being called by a function.

void whoAmI(Bird* b) {
    printf("Hello! I am %s. I am %d years old. I am a %s bird.\n", b->name, b->age, b->breed);
    printf("Meek Meek!\n");
}

void pointerCount(int* p, int a[]) {
    

    for (int i = 0; i < 20; i++) {
        printf("pointer -> %d   pointer memory -> %d \n", *p, p);
        p++;
    }
}