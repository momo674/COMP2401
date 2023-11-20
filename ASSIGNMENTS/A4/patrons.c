#include "defs.h"

void initPatronArray(PatronArrayType *arr) {

    arr->elements = calloc(MAX_CAP, sizeof(PatronType));
    arr->size = 0;
    arr->nextId = PATRON_IDS;

}

void addPatron(PatronArrayType *arr, char *n) {

    PatronType item;
    item.id = arr->nextId;
    strcpy(item.name, n);

    arr->elements[arr->size] = item;
    ((*(arr)).size)++;
    ((*(arr)).nextId)++;

}

int findPatron(PatronArrayType *arr, int id, PatronType **p){

    for (int i = 0; i < arr->size; i++) {
        
        if ((arr->elements)[i].id == id) {
            PatronType saved = arr->elements[i];
            *p = arr->elements + i;
                    
        
            return C_OK;

        }

    }

    return C_NOK;
}

void printPatrons(PatronArrayType *arr){

    printf("REGISTERED PATRONS at Christine's Bistro:\n");

    for (int i = 0; i < arr->size; i++) {
        printf("Patron #%d %s\n", arr->elements[i].id, arr->elements[i].name);
        
    }

}

void cleanupPatronArray(PatronArrayType *arr){

    free(arr->elements);
    free(arr);
    
} 