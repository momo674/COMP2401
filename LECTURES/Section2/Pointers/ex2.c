
#include <stdio.h>
#include <string.h>


void add(int*);
void big(int*);


struct Person{
	
	int age;
	int id;
	char name[50];

};

void setName(struct Person* p , char newname[]);


int main() {
	

	
	struct Person first;
	struct Person* fPtr = &first;
	
	fPtr->age = 13;
	strcpy(fPtr->name, "Mohamad Radaideh");
	(*fPtr).age = 10; //noob way of derefecing
	printf("age: %d", fPtr->age);
	printf("name: %s\n", fPtr->name);


}



void add(int* x) {
		
	(*x)++;

}

void big(int* x) {

	*x = 9999;

}

void setName(struct Person* x , char newname[]) {
	x->name;
	strcpy(x->name, newname);
}


