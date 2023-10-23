

#include <stdio.h>

void add(int*);
void big(int*);

int main() {
	int x = 5;
	int y = 10;
	int* yPtr = &y;
	int** yPtr2 = &yPtr;

	add(&x);
	//add(&y);
	big(*yPtr2);

	printf("After add: x = %d y = %d \n", x, y);



}



void add(int* x) {
		
	(*x)++;

}

void big(int* x) {
	*x = 9999;
}

