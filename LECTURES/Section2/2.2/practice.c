#include <stdio.h>
#include <string.h>


struct Person {
    int age;
    char f_name[32];
};

struct Student {
    struct Person basic_info;
    int student_id;

};
void printStudent(struct Student);

int main() {
    struct Student Mohamad;
    Mohamad.basic_info.age = 19;
    strcpy(Mohamad.basic_info.f_name, "Mohamad");
    Mohamad.student_id = 12345678;

    printStudent(Mohamad);
    return 0;
}


void printStudent(struct Student s) {
    printf("NAME: %s AGE: %d ID: %d\n", s.basic_info.f_name, s.basic_info.age, s.student_id);
}


