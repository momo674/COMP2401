#include <stdio.h>

// Define a simple structure
typedef struct {
    int x;
    int y;
} Point;

// Function definition
void printPoint(Point* p) {
    printf("Point coordinates: (%d, %d)\n", p->x, p->y);
}

int main() {
    // Create an instance of the Point struct
    Point myPoint;
    myPoint.x = 10;
    myPoint.y = 20;

    // Call the printPoint function directly with a pointer to the struct
    printPoint(&myPoint);

    return 0;
}
