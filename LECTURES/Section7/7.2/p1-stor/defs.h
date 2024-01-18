#include <stdio.h>
#include <string.h>

#define MAX_SIZE 64
#define C_OK      0
#define C_NOK    -1

typedef struct { 
  int elements[MAX_SIZE];
  int size;
} ArrayType;

void initArray(ArrayType*);
void printArray(ArrayType*);
int  fillArray(ArrayType*, int);
void shuffleArray(ArrayType*, ArrayType*);
void addToArray(ArrayType*, int);
void addFront(ArrayType*, int);
void addBack(ArrayType*, int);

