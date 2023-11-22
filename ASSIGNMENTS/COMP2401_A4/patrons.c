#include "defs.h"

/*
  Function:  initPatronArray
  Purpose:   initializes Patron Array structre.
       in:   arr - PatronArrayType passed by reference which is garbage.
       out:  arr - updated structre with a dynamic block of memory and default values.
*/
void initPatronArray(PatronArrayType *arr) {

    arr->elements = calloc(MAX_CAP, sizeof(PatronType));
    arr->size = 0;
    arr->nextId = PATRON_IDS;

}

/*
  Function:  addPatron
  Purpose:   Adds a new Patron to PatronArrayType element array.
       in:   arr - PatronArrayType passed by reference.
       in:   n - string which consists of name of new Patron.
       out:  arr - updated structre with new Patron in element's array, size increased aswell as nextId incremented.
*/
void addPatron(PatronArrayType *arr, char *n) {

    PatronType item;
    item.id = arr->nextId;
    strcpy(item.name, n);

    arr->elements[arr->size] = item;
    arr->size++;
    ((*(arr)).nextId)++;

}

/*
  Function:  findPatron
  Purpose:   Attempts to find Patron by it's ID.
       in:   arr - PatronArrayType passed by reference.
       in:   id - integer of Patron to be found.
       in:   **p - empty PatronType pointer.
       out:  **p - pointing at found Patron.
    return:  (integer) C_OK if found, otherwise C_NOK .
*/
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

/*
  Function:  printPatrons
  Purpose:   prints all present patrons in PatronArrayType structure.
       in:   arr - PatronArrayType passed by reference.
*/
void printPatrons(PatronArrayType *arr){

    for (int i = 0; i < arr->size; i++) {

        printf("Patron #%d %s\n", arr->elements[i].id, arr->elements[i].name);
        
    }

}

/*
  Function:  cleanupPatronArray
  Purpose:   frees all dynamically stored items in structre.
       in:   arr - PatronArrayType passed by reference.
       out:  arr - free of memory leaks.
*/
void cleanupPatronArray(PatronArrayType *arr){

    free(arr->elements);
    
} 