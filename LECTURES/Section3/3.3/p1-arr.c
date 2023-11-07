#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STU  16
#define MAX_STR  32

typedef struct {
  char name[MAX_STR];
  char major[MAX_STR];
} StudentType;

void initStudentStruct(char*, char*, StudentType*);
void initStudentPtr(char*, char*, StudentType**);
void printStudent(StudentType*);


int main()
{
  StudentType matilda, joe, timmy;
  int numStu = 3;

  initStudentStruct("Matilda", "CS", &matilda);
  initStudentStruct("Joe", "Physics", &joe);
  initStudentStruct("Timmy", "CS", &timmy);

  printf("\nStatically allocated array of StudentType structures...\n");

  StudentType arr1[MAX_STU];

  arr1[0] = matilda;
  arr1[1] = joe;
  arr1[2] = timmy;

  for (int i=0; i<numStu; ++i) {
    printStudent(arr1 + i);
  }

  printf("\nStatically allocated array of StudentType pointers...\n");

  StudentType *arr2[MAX_STU];

  arr2[0] = &timmy;
  initStudentPtr("Harold", "basket-weaving", arr2+1);
  initStudentPtr("Amy", "cog-sci", arr2+2);

  for (int i=0; i<numStu; ++i) {
    printStudent(arr2[i]);
  }

  free(arr2[1]);
  free(arr2[2]);

  printf("\nDynamically allocated array of StudentType structures...\n");

  StudentType *arr3;

  arr3 = calloc(numStu, sizeof(StudentType));

  arr3[0] = timmy;
  arr3[1] = matilda;
  arr3[2] = joe;

  for (int i=0; i<numStu; ++i) {
    printStudent(arr3 + i);
  }

  free(arr3);

  printf("\nDynamically allocated array of StudentType pointers...\n");

  StudentType **arr4;

  arr4 = calloc(numStu, sizeof(StudentType*));

  initStudentPtr("Harold", "basket-weaving", arr4);
  initStudentPtr("Amy", "cog-sci", arr4+1);
  arr4[2] = &matilda;

  for (int i=0; i<numStu; ++i) {
    printStudent(arr4[i]);
  }

  free(arr4[0]);
  free(arr4[1]);
  free(arr4);


  return 0;
}

void initStudentStruct(char *n, char *m, StudentType *stu)
{
  strcpy(stu->name,  n);
  strcpy(stu->major, m);
}

void initStudentPtr(char *n, char *m, StudentType **stu)
{
  StudentType *tmpStu;

  tmpStu = (StudentType*) malloc(sizeof(StudentType));
  strcpy(tmpStu->name,  n);
  strcpy(tmpStu->major, m);

  *stu = tmpStu;
}

void printStudent(StudentType *stuPtr)
{
  printf("Student:  %10s;  major:  %15s\n",
          stuPtr->name, stuPtr->major);
}

