#include <stdio.h>
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

void printStudent(StudentType);


int main()
{
  StudentType matilda, joe;
  StudentType comp2401[NUM_STU];
  StudentType *stuPtr;

  strcpy(matilda.basicInfo.first, "Matilda");
  strcpy(matilda.basicInfo.last,  "Moore");
  matilda.basicInfo.age = 22;
  strcpy(matilda.stuNumber, "100444555");
  matilda.gpa = 9.0;

  strcpy(joe.basicInfo.first, "Joe");
  strcpy(joe.basicInfo.last,  "JumpsALot");
  joe.basicInfo.age = 24;
  strcpy(joe.stuNumber, "100222333");
  joe.gpa = 8.7;

  comp2401[0] = matilda;
  comp2401[1] = joe;

  strcpy(comp2401[2].basicInfo.first, "Timmy");
  strcpy(comp2401[2].basicInfo.last,  "Tortoise");
  comp2401[2].basicInfo.age = 99;
  strcpy(comp2401[2].stuNumber, "100777888");
  comp2401[2].gpa = 11.5;

  printf("\n");

  stuPtr = comp2401;

  printf("\nStudents with GPA >= 9:\n");

  for (int i=0; i<3; ++i) {
    if (stuPtr->gpa >= 9) {
      printf("%s %s has a GPA over 9\n", stuPtr->basicInfo.first,
             stuPtr->basicInfo.last);
    }

    ++stuPtr;
  }


  return 0;
}

void printStudent(StudentType stu)
{
  printf("Student #%s:  %s %s, age %d, gpa %.1f\n",
          stu.stuNumber, stu.basicInfo.first, stu.basicInfo.last,
          stu.basicInfo.age, stu.gpa);
}

