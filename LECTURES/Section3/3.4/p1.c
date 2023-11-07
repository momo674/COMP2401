#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STR 32
//bad design;

//we should not hardcode next into our Structre. should ot mix element and list data.
typedef struct Student
{
    char name[MAX_STR];
    char major[MAX_STR];
    struct Student *next;
    
} StudentType;


void initStudent(char*, char*, StudentType*);
void printStudent(const StudentType*);

int main()
{
    StudentType *comp2401 = NULL;
    StudentType *newStu;

    char str1[MAX_STR];
    char str2[MAX_STR];
    
    while (1) 
    {
        //loop needs to be copied
    }
}



void initStudent(char* name, char* major, StudentType* student)
{
    strcpy(student->name, *name);
    strcpy(student->major, *major);
    student-> next = NULL;

}