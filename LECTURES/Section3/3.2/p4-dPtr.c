#include <stdio.h>
#include <stdlib.h>

void doInitBad(int);
void doInitGood(int*);

void doAllocBad(int*);
void doAllocGood(int**);
void pointer(int**, int*);

int main()
{
  int  num;
  int *ptr;

//   doInitBad(num);
//   printf("%d\n", num);

//   doInitGood(&num);
//   printf("%d\n", num);
//   doAllocBad(ptr);
// //  printf("%d\n", *ptr);

//   doAllocGood(&ptr);
//   printf("%d\n", *ptr);

  int x = 1;

  int* p = &x;
  int* p2 = &x;
  
  int* po;
  pointer(&po, &x);
  printf("Pointer points to: %d\n", *po);
    return 0;

}

void pointer(int** p, int* x) {
  *p = x;
  **p += 10;
}

void doAllocGood(int **p)
{
  *p = malloc(sizeof(int));
  **p = 80;
}

void doAllocBad(int *p)
{
  p = malloc(sizeof(int)); //not modifiying orignial pointer
  *p = 80;
  //POINTER WILL NOW DEREFENECE TO 80; HOWEVER ORIGINAL POINTER WILL NOT POINT TO
  //BLOCK OF MEMORY.
  //p = malloc(sizeof(int)) basically
}

void doInitGood(int *n)
{
  *n = 77;
}

void doInitBad(int n)
{
  n = 77;
}





//when you pass a pointer by value, any changes to the pointer (where it points to) will not effect original pointer.
//ex:
/*
  void pass(int* x) {
    x = &GLOBAL_INT_VARIABLE
  }
*/


/*
  if we have a function, which sets the pointer to derefence at a value, we can pass by value
  if we have a function where pointer is pointing malloc address, we must use double pointer
    -> if we dont, this will happen

    int* pointer;
    init(pointer);
    printf(*pointer) will be NULL. The heap has a block of 10 bytes not used aswell.
    
    void init(*p){
      p = malloc(10);
    }

*/