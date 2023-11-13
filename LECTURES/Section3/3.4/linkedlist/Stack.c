#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 32

typedef struct{
    int id;
    char name[MAX_LENGTH];
} StudentType;

typedef struct NodeType {
    struct NodeType* next;
    StudentType* data;

} Node;

void initStudent(StudentType** student, char* name, int id);
void initNode(Node** node, StudentType** stu);
void push(Node** list, Node* item, int* size);
void displayStack(Node* list);
void pop(Node* list, int* size);
void add(Node* list, Node* item, int* size, int index);

int main() {

    int size = 0;
    StudentType* bob;
    initStudent(&bob,"bob",18);
    Node* bob_node;
    initNode(&bob_node,&bob);

    StudentType* momo;
    initStudent(&momo,"momo",19);
    Node* momo_node;
    initNode(&momo_node,&momo);

    StudentType* franklin;
    initStudent(&franklin,"franklin",20);
    Node* franklin_node;
    initNode(&franklin_node,&franklin);

    StudentType* cosmo;
    initStudent(&cosmo,"cosmo",21);
    Node* cosmo_node;
    initNode(&cosmo_node,&cosmo);


    Node* lecturehall = malloc(sizeof(Node));

    
    

    // add(lecturehall,bob_node,&size,0);
    // displayStack(lecturehall);

    push(&lecturehall,momo_node,&size);
    displayStack(lecturehall);

    // push(lecturehall,franklin_node,&size);
    // displayStack(lecturehall);

    // push(lecturehall,cosmo_node,&size);
    // displayStack(lecturehall);


    // pop(lecturehall, &size);
    // displayStack(lecturehall);

    // pop(lecturehall, &size);
    // displayStack(lecturehall);

    // pop(lecturehall, &size);
    // displayStack(lecturehall);

    // pop(lecturehall, &size);
    // displayStack(lecturehall);


    // //try to pop on an empty stack.
    // pop(lecturehall, &size);
    // displayStack(lecturehall);



}

void initStudent(StudentType** student, char* name, int id) {
    *student = (StudentType*) malloc(sizeof(StudentType));
    (*student)->id = id;
    strcpy((*student)->name, name);
}

void initNode(Node** node, StudentType** stu) {
    *node = malloc(sizeof(Node));
    (*node)->data = *stu;
    (*node)->next = NULL;
}

void push(Node** list, Node* item, int* size) {
    Node* current = *list;

    if (size == 0) {
        *list = item;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = item;
    (*size)++;
}

void displayStack(Node* list) {
    Node* current = list;
    printf("bottom -> :");
    while (current != NULL) {
        printf(" %s", current->data->name);
        current = current->next;
    }
    printf(" : <- top\n\n");
}

void pop(Node* list, int* size){
    if (*size <= 0) {
        printf("ERROR: STACK IS EMPTY\n");
        return;
    }
    Node* current = list;
    Node* current_prev;
    while (current->next != NULL) {
        current_prev = current;
        current = current->next;
    }
    //once we break from loop, then we know current is the last item in list
    current_prev->next = NULL;
    (*size)--;
}

void add(Node* list, Node* item, int* size, int index) {
    if (index > *size) {
        printf("ERROR: INVALID INDEX TO ADD AT.\n");
        return;
    }

    Node* curr = list;
    Node* prev = NULL;
    int currPos = 0;

    if ((*size) == 0 ) { //list is empty
        list = item;
        (*size)++;
        return;
    }

    /*  There are a few cases to adding
        1. List is empty.
        2. adding to front
        3. adding to middle
        4. adding to back (push)
    */
}