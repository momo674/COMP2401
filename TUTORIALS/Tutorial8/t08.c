#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "t08defs.h"

/* Implement StudentNode type */
typedef struct StuNode {
  struct StuNode* next;
  StudentType* data;
} StudentNode;

typedef struct {
  StudentNode *head;
} StudentList;


/* Implement the following functions */
void addStudent(StudentList *, StudentNode *);
void printList(const StudentList *);
void appendStudent(StudentList *stuList, StudentNode *a);


int main(void) {
  int i;
  
  StudentType matilda, joe, timmy;
  StudentNode matildaNode, joeNode, timmyNode;

  initStudent("Matilda", "Mallister", 22, "123444555",
              9.0, &matilda);
  initStudent("Joe", "The Plumber", 24, "567888999",
              8.7, &joe);
  initStudent("Timmy", "Tortoise", 99, "345667788",
              11.5, &timmy); 
 
  matildaNode.data = &matilda;
  joeNode.data = &joe;
  timmyNode.data = &timmy;

  StudentList comp2401;

  comp2401.head = NULL;

/*  Uncomment the following lines once addStudent is implemented  */

 appendStudent(&comp2401, &matildaNode);
 appendStudent(&comp2401, &joeNode);
 appendStudent(&comp2401, &timmyNode);

/*  Uncomment the following line once printList is implemented  */

 printList(&comp2401);

  return 0;
}

/*   Function:  addStudent                                  */
/*         in:  Location of StudentList to be modified      */
/*         in:  Location of StudentType to be added         */
/*        out:  StudentList with added StudentType          */
/*    Purpose:  adds stu to stuList at the head of the list */
void addStudent(StudentList *stuList, StudentNode *stuNode) {
  stuNode->next = stuList->head;
  stuList->head = stuNode;
  
  /*
    head->next = new item
    new item->next = 
  */
}

void appendStudent(StudentList *stuList, StudentNode *a) {
  if (stuList->head == NULL) {
    stuList->head = a;
    return;
  }
  StudentNode* current = stuList->head;
  

  while (current->next != NULL) {
    current = current->next;
  }
  current->next = a;
}

void printList(const StudentList *stuList) {
  StudentNode* currNode = stuList->head;
  while (currNode != NULL) {
    printStudent(currNode->data);
    currNode = currNode->next;
  }
  
}
