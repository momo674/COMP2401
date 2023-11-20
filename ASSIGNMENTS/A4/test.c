#include "defs.h"

int main() {
    PatronArrayType arr;
    PatronType* test = NULL;
    initPatronArray(&arr);
    addPatron (&arr, "bob");
        addPatron (&arr, "b");

    addPatron (&arr, "c");

    addPatron (&arr, "bdob");

    findPatron(&arr, 1001, &test);
    

    printPatrons(&arr);
    return 0;
}