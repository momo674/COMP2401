#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR  32
#define NUM_STU 150

typedef struct {
  char first[MAX_STR];
  char last[MAX_STR];
  int  age;
} PersonType;

typedef struct {
  PersonType basicInfo;
  char       stuNumber[12];
  float      gpa;
} StudentType;

void initStudent(char*, char*, int, char*, float, StudentType*);
void printStudent(const StudentType*);


int main()
{
  StudentType *comp2401;
  int numStu;
  char str1[MAX_STR];
  char str2[MAX_STR];
  char str3[MAX_STR];
  int  age;
  float gpa;

  printf("How many students do we have: ");
  scanf("%d", &numStu);

  comp2401 = calloc(numStu, sizeof(StudentType));
  /*
    How couldwe convert into malloc
    1. comp2401 = malloc(numStu * sizeOf(StudentType))
    2. StudentType* loop = comp2401

    for (int i= 0; i < numStu; i++){
      *loop = blankStudentType; //use a blank studentType
      loop++;
    }

    now our block of memory is initalized, instead of null it is all empty student types.
  */
  for (int i=0; i<numStu; ++i) {
    printf("Enter first name last name: ");
    scanf("%s %s", str1, str2);
    printf("age: ");
    scanf("%d", &age);
    printf("stu number: ");
    scanf("%s", str3);
    printf("gpa: ");
    scanf("%f", &gpa);

    initStudent(str1, str2, age, str3, gpa, comp2401+i);
  }
  
  printf("\nCLASS LIST:\n");
  for (int i=0; i<numStu; ++i) {
    printStudent(comp2401+i);
  }

  return 0;
}


void initStudent(char *f, char *l, int a, char *n, float g, StudentType *stu)
{
  strcpy(stu->basicInfo.first, f);
  strcpy(stu->basicInfo.last, l);
  stu->basicInfo.age = a;
  strcpy(stu->stuNumber, n);
  stu->gpa = g;
}


void printStudent(const StudentType *stuPtr)
{
  printf("Student #%s:  %10s %10s, age %2d, gpa %4.1f\n",
          stuPtr->stuNumber, stuPtr->basicInfo.first, stuPtr->basicInfo.last,
          stuPtr->basicInfo.age, stuPtr->gpa);
}

