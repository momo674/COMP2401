#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NodeStruct{
    int data;
    struct NodeStruct* next;
} Node;

void displayList(Node* list, int size);
void addBack(Node* list, int element);

int main(){
    int size = 0;
    Node* list = malloc(sizeof(Node));
    list->next = NULL;
    //displayList(list,size);

    addBack(list,10);
    addBack(list,10);
    addBack(list,10);
    addBack(list,10);
    addBack(list,10);
    addBack(list,10);
    addBack(list,10);
    addBack(list,10);
    addBack(list,10);


    displayList(list, size + 9);

    
}

void displayList(Node* list, int size) {
    Node* current = list;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void addBack(Node* list, int element){
    Node* current = list;
    Node* item = malloc(sizeof(Node));
    item->next = NULL;
    item->data = element;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = item;
}