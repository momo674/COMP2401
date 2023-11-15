#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 32

typedef struct StudentStruct
{
    int id;
    char name[MAX_STR];

} Student;

typedef struct NodeStruct 
{
    struct NodeStruct* next;
    Student* data;

} Node;

void initStu(Student** stu, int id, char* name);
void addInList(int index, Node** list, Student* element);
void removeInList(int index, Node** list);
void displayList(Node* list);
void cleanUp(Node* list);

int main()
{

    Student* momo1;
    initStu(&momo1, 1, "momo1");

    Student* momo2;
    initStu(&momo2, 2, "momo2");

    Student* momo3;
    initStu(&momo3, 3, "momo3");

    Student* momo4;
    initStu(&momo4, 4, "momo4");

    Student* momo5;
    initStu(&momo5, 5, "momo5");

    Student* momo6;
    initStu(&momo6, 6, "momo6");

    Node* list = NULL;
    int size = 0;
    
    displayList(list);

    addInList(0,&list,momo1);
    addInList(1,&list,momo2);
    addInList(2,&list,momo3);
    addInList(3,&list,momo4);
    addInList(4,&list,momo5);
    addInList(5,&list,momo6);

    displayList(list);

    removeInList(3,&list);
    displayList(list);


    cleanUp(list);
    return 0;
}

void initStu(Student** stu, int id, char* name)
{

    *stu = (Student*) malloc(sizeof(Student));
    (*stu)->id = id;
    strcpy((*stu)->name, name);
    return;
}

void addInList(int index, Node** list, Student* element)
{
    Node* currNode = *list;
    Node* prevNode = NULL;
    int i = 0;

    Node* elementAsNode = malloc(sizeof(Student));
    elementAsNode->data = element;
    elementAsNode->next = NULL;

    while (currNode != NULL)
    {
        if (i == index)
            break;
        
        prevNode = currNode;
        currNode = currNode->next;
        ++i;
    }

    if (i != index)
    {
        printf("ERROR: INCORRECT INDEX\n");
        return;
    }

    if (prevNode == NULL)
    {
        *list = elementAsNode;
    }

    else
    {
        prevNode->next = elementAsNode;
    }

    elementAsNode->next = currNode;

}

void removeInList(int index, Node** list)
{
    Node* currNode;
    Node* prevNode;

    currNode = *list;
    prevNode = NULL;

    int pos = 0;

    while (currNode != NULL) 
    {
        if (pos == index)
        {
            break;
        }

        prevNode = currNode;
        currNode = currNode->next;

    }

    if (currNode == NULL) {
        return;
    }

    if (prevNode == NULL) {
        *list = currNode->next;
    }
    else {
        prevNode->next = currNode->next;
    }
    
    free(currNode->data);
    free(currNode);
    


}

void displayList(Node* list)
{

    Node* currNode = list;
    while (currNode != NULL)
    {
        printf("%s ", currNode->data->name);
        currNode = currNode->next;
    }
    printf("\n");
    return;

}

//study
void cleanUp(Node* list)
{
    Node* prevNode;
    Node* nextNode;
    Node* currNode;

    currNode = list;
    prevNode = NULL;
    nextNode = NULL;

    while (currNode != NULL) {
        nextNode = currNode->next;
        free(currNode->data);
        free(currNode);
        currNode = nextNode;
    }

}