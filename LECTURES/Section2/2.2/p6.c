#include <stdio.h>
#include <string.h>
#define MAX_STR 32
#define NUM_STU 150


struct PersonType {
    char first[MAX_STR];
    char last[MAX_STR];
    int age;
};

struct StudentType {
    struct PersonType basicInfo;
    char stuNumber[12];
    float gpa;
};

void printStudent(struct StudentType);
int main() {
    struct PersonType gertrude;
    struct StudentType stuGert;
    struct StudentType matilda, joe;
    strcpy(gertrude.first, "Gertrude");
    strcpy(gertrude.last, "Queensway-Westbound");
    gertrude.age = 99;

    printf("\n SIZE OF PERSON: %ld\n", sizeof(struct PersonType)); //prints 68 bytes
    printf("\n SIZE OF STUDENT: %ld\n", sizeof(struct StudentType)); //prints 84 bytes

    stuGert.basicInfo = gertrude;
    strcpy(stuGert.stuNumber, "100222333");
    stuGert.gpa = 9.3;

    strcpy(matilda.basicInfo.first, "Matilda");
    strcpy(matilda.basicInfo.last, "Moore");
    matilda.basicInfo.age = 22;
    strcpy(matilda.stuNumber, "1000999888");
    matilda.gpa = 9.0;

    strcpy(joe.basicInfo.first, "Joe");
    strcpy(joe.basicInfo.last, "JumpsALot");
    joe.basicInfo.age = 24;
    strcpy(joe.stuNumber, "1000888777");
    joe.gpa = 8.7;

    printStudent(stuGert);
    printStudent(matilda);
    printStudent(joe);

    //struct StudentType 2401[NUM_STU];

    return 0;
}

void printStudent(struct StudentType stu) {
    printf("Student #%s: %s %s, age %d, gpa %.1f\n", stu.stuNumber, stu.basicInfo.first, stu.basicInfo.last, stu.basicInfo.age, stu.gpa);
}