#include "defs.h"

void initRestaurant(RestaurantType *r, char *n) {
    strcpy(r->name, n);
    initResvList(&(r->reservations));
    initPatronArray(&(r->patrons));
}

int validateResvTime(int yr, int mth, int day, int hr, int min) {
    if (yr < 2023 || (mth > 12) || (mth < 1) || (day > 31) || (day < 1) || (hr > 24) || (hr < 1) || (min > 60) || (min < 0)) {
        return C_NOK;
    }

    return C_OK;
}

void createResv(RestaurantType *r, int pId, int yr, int mth, int day, int hr, int min) {
    //check date
    int date_check = validateResvTime(yr, mth, day, hr, min);
    if (date_check == C_NOK) {
        printf("ERROR: Date %d-%d-%d or time %d:%d is invalid\n", yr,mth,day,hr,min);
    }
    PatronType* newPatron;
    int patron_check = findPatron(&(r->patrons), pId, &newPatron);
    

    if (patron_check == C_NOK) {
        printf("ERROR: Patron id %d was not found\n", pId);
    }

    if (patron_check == C_NOK || date_check == C_NOK) {
        return;
    }

    ResvTimeType* newResvTimeType;
    initResvTime(&newResvTimeType, yr, mth, day, hr, min);

    ResvType* newRes;
    initResv(&newRes, newPatron, newResvTimeType);

    addResv(&(r->reservations), newRes);
}

void printResByPatron(RestaurantType *r, int id) {
    NodeType *currNode = r->reservations.head;
    NodeType *prevNode = NULL;

    printf("RESERVATIONS BY PATRON at Christine's Bistro:\n");
    while (currNode != NULL) {
        if (currNode->data->patron->id == id) {
            printReservation(currNode->data);
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    
}

void cleanupRestaurant(RestaurantType *r) {
    cleanupResvList(&(r->reservations));
    cleanupPatronArray(&(r->patrons));
    //free(r->name);
    
}
