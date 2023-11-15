#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C_OK      0
#define C_NOK    -1
#define MAX_STR  32

typedef struct {
  char name[MAX_STR];
  char major[MAX_STR];
} StudentType;

typedef struct {
  int           size;
  StudentType **elements;
} ArrayType;


void initStudent(char*, char*, StudentType**);
void printStudent(StudentType*);
int  addStudent(ArrayType*, StudentType*, int);
void printStudents(ArrayType*);
void cleanupStudents(ArrayType*);


int main()
{
  ArrayType comp2401;
  StudentType *newStu;
  char  str1[MAX_STR];
  char  str2[MAX_STR];
  int   pos, rc;

  comp2401.size = 0;
  comp2401.elements = NULL;

  while (1) {
    printf("Enter name: ");
    scanf("%s", str1);
    if (strcmp(str1, "-1") == 0)
      break;
    printf("Enter major: ");
    scanf("%s", str2);
    printf("Enter position: ");
    scanf("%d", &pos);

    initStudent(str1, str2, &newStu);
    rc = addStudent(&comp2401, newStu, pos);

    if (rc < 0) {
      printf("Student could not be added\n");
      free(newStu);
    }
  }

  printStudents(&comp2401);
  cleanupStudents(&comp2401);

  return 0;
}

int addStudent(ArrayType *arr, StudentType *stu, int pos)
{
  StudentType **tmpArr;
  int index;

  if (pos > arr->size || pos < 0) {
    return C_NOK;
  }

  tmpArr = calloc(arr->size+1, sizeof(StudentType*));

  for (index=0; index<pos; ++index) {
    tmpArr[index] = arr->elements[index];
  }

  tmpArr[index] = stu;

  for (; index<arr->size; ++index) {
    tmpArr[index+1] = arr->elements[index];
  }

  free(arr->elements);
  arr->elements = tmpArr;
  arr->size++;

  return C_OK;
}

void printStudents(ArrayType *arr)
{
  printf("\n");
  for (int i=0; i<arr->size; ++i) {
    printStudent(arr->elements[i]);    
  }
  printf("\n");
}

void initStudent(char *n, char *m, StudentType **stu)
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

void cleanupStudents(ArrayType *arr)
{
  for (int i=0; i<arr->size; ++i) {
    free(arr->elements[i]);
  }

  free(arr->elements);
  arr->elements = NULL;
}

