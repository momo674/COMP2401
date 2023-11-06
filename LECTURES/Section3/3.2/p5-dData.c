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

void initStudent(char*, char*, int, char*, float, StudentType**);
void printStudent(const StudentType*);
void cleanup(StudentType**, int);


int main()
{
//  StudentType* comp2401[NUM_STU];	// C++ style
  StudentType *comp2401[NUM_STU];	// C style

  int   numStu;
  char  str1[MAX_STR];
  char  str2[MAX_STR];
  char  str3[MAX_STR];
  int   int1;
  float f1;

  printf("How many students do we have? ");
  scanf("%d", &numStu);

  for (int i=0; i<numStu; ++i) {
    printf("Enter first name: ");
    scanf("%s", str1);
    printf("Enter last name: ");
    scanf("%s", str2);
    printf("Enter age: ");
    scanf("%d", &int1);
    printf("Enter student number: ");
    scanf("%s", str3);
    printf("Enter gpa: ");
    scanf("%f", &f1);

    initStudent(str1, str2, int1, str3, f1, comp2401+i);

  }

  printf("\n\nLIST:\n");

  for (int i=0; i<numStu; ++i) {
//    printStudent(*(comp2401+i));
    printStudent(comp2401[i]);
  }

  printf("\n");
  cleanup(comp2401, numStu);

  return 0;
}


void initStudent(char *f, char *l, int a, char *n, float g, StudentType **stu)
{
  StudentType *tmpStu;


  tmpStu = malloc(sizeof(StudentType));

  strcpy(tmpStu->basicInfo.first, f);
  strcpy(tmpStu->basicInfo.last, l);
  tmpStu->basicInfo.age = a;
  strcpy(tmpStu->stuNumber, n);
  tmpStu->gpa = g;

  *stu = tmpStu; 
}


void printStudent(const StudentType *stuPtr)
{
  printf("Student #%s:  %10s %10s, age %2d, gpa %4.1f\n",
          stuPtr->stuNumber, stuPtr->basicInfo.first, stuPtr->basicInfo.last,
          stuPtr->basicInfo.age, stuPtr->gpa);
}

void cleanup(StudentType **arr, int numStu)
{
  for (int i=0; i<numStu; ++i) {
    free(arr[i]);
  }
}

