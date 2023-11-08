#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR  32

typedef struct Student {
  char name[MAX_STR];
  char major[MAX_STR];
} StudentType;

typedef struct Node{
    StudentType *data;
    struct Node *next;
} NodeType;


void initStudent(char*, char*, StudentType**);
void printStudent(const StudentType*);
void printStudents(NodeType*);

void addStudent(NodeType* *, StudentType*, int);

int main()
{
  NodeType *comp2401 = NULL;
  NodeType *newNode;

  StudentType *newStu;

  char  str1[MAX_STR];
  char  str2[MAX_STR];
  int pos;

  while (1) {
    printf("Enter name: ");
    scanf("%s", str1);
    if (strcmp(str1, "-1") == 0)
      break;
    printf("Enter major: ");
    scanf("%s", str2);

    printf("%d", &pos);
    initStudent(str1, str2, &newStu);
    addStudent(&comp2401, newStu, 0);

  }
  printStudents(comp2401);

  return 0;
}

void printStudents(NodeType* head)
{
  NodeType *currNode = head;

  while (currNode != NULL) {
    printStudent(currNode->data);
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

void addStudent(NodeType* *head, StudentType* student, int pos) {
    NodeType *newNode;
    NodeType *currNode;
    NodeType *prevNode;
    int currPos = 0;

    newNode = malloc(sizeof(NodeType));
    //why malloc here?
    newNode->data = student;
    newNode->next = NULL;


    currNode = *head;
    prevNode = NULL;

    while (currNode != NULL) {
        if (currPos == pos) {
            break;
        }
        ++currPos;
        prevNode = currNode;
        currNode = currNode -> next;
    }  

    if (currPos != pos) {
        printf("invalid posistion\n");
        return;
    }

    if (prevNode == NULL) {
        *head = newNode;
    }
    else {
        prevNode->next = newNode;
    }
    newNode->next = currNode;
}


