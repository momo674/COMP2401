#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR  32

typedef struct Student {
  char name[MAX_STR];
  char major[MAX_STR];
  struct Student *next;
} StudentType;

void initStudent(char*, char*, StudentType**);
void printStudent(const StudentType*);
void printStudents(StudentType*);


int main()
{
  StudentType *comp2401 = NULL;
  StudentType *newStu;

  char  str1[MAX_STR];
  char  str2[MAX_STR];

  while (1) {
    printf("Enter name: ");
    scanf("%s", str1);
    if (strcmp(str1, "-1") == 0)
      break;
    printf("Enter major: ");
    scanf("%s", str2);

    initStudent(str1, str2, &newStu);

    newStu->next = comp2401;
    comp2401 = newStu;
  }

  printStudents(comp2401);

  return 0;
}

void printStudents(StudentType *list)
{
  StudentType *currNode = list;

  while (currNode != NULL) {
    printStudent(currNode);
    currNode = currNode->next;
  }
}

void initStudent(char *n, char *m, StudentType **stu)
{
  StudentType *tmpStu;

  tmpStu = (StudentType*) malloc(sizeof(StudentType));
  strcpy(tmpStu->name,  n);
  strcpy(tmpStu->major, m);

  *stu = tmpStu;
}

void printStudent(const StudentType *stuPtr)
{
  printf("Student:  %10s, major:  %15s\n",
          stuPtr->name, stuPtr->major);
}

