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