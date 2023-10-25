#include <stdio.h>


void add(int*);

int main() {
	
	int x = 7;
	int *xPtr = &x;
	
	printf("Pointer = %d Variable = %d\n", x, xPtr);
	
	//A pointer stores an address, when we call xPtr, we are dealing with the address stored
	//that points to x
	//
	//Now when we call &xPtr, we are calling the address of the pointer (Its own address)
	//
	//If we want the value of the pointer, we deference it.
	printf("Pointer being called = %d Pointer deref = %d Pointer address = %d\n",xPtr,*xPtr,&xPtr);
	printf("Size of Pointer %d\n", sizeof(*xPtr));
	
	printf("Attempt: %d/n/n/n" *xPtr++);

	printf("Before add: Pointer = %d", *xPtr);
	
	add(xPtr);

	printf(" After add: Pointer = %d\n", *xPtr);
}


void add(int *x) 
{
	
	(*x)++;
	*x = *x + 1;
}


