#include "defs.h"

/*
  Function:  initResturant
  Purpose:   initizales ResturantType structure while also naming it.
       in:   r - RestaurantType passed by reference that is filled with garbage.
       in:   n - String of desired name.
      out:   r - ResturantType structre that is named, initalized Reservation List, initialzed Patron List.
*/
void initRestaurant(RestaurantType *r, char *n) {

    strcpy(r->name, n);
    initResvList(&(r->reservations));
    initPatronArray(&(r->patrons));

}

/*
  Function:  validateResvTime
   Purpose:   Determines if date is a correct date.
        in:   yr - int representing year.
        in:  mth - int representing month.
        in:  day - int representing day.
        in:   hr - int representing hr.
        in:  min - int representing min.
    return:   (int) C_OK if valid, otherwise C_NOK.
*/
int validateResvTime(int yr, int mth, int day, int hr, int min) {

    if (yr < 2023 || (mth > 12) || (mth < 1) || (day > 31) || (day < 1) || (hr > 24) || (hr < 1) || (min > 60) || (min < 0)) {

        return C_NOK;
    }

    return C_OK;
}

/*
  Function:   createResv
   Purpose:   creates a reservation for resturant.
        in:   *r - ResturantType structure passed by reference (Resturant).
        in:  pId - int value of Patron ID.
        in:   yr - int representing year.
        in:  mth - int representing month.
        in:  day - int representing day.
        in:   hr - int representing hr.
        in:  min - int representing min.
       out:   *r - (Resturant) with new Reservation.
*/
void createResv(RestaurantType *r, int pId, int yr, int mth, int day, int hr, int min) {

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

/*
  Function:   printResByPatron
   Purpose:   prints all Reservations made by Patron.
        in:   *r - ResturantType structure passed by reference (Resturant).
        in:   id - int value of Patron ID.
*/
void printResByPatron(RestaurantType *r, int id) {

    NodeType *currNode = r->reservations.head;
    NodeType *prevNode = NULL;

    while (currNode != NULL) {

        if (currNode->data->patron->id == id) {

            printReservation(currNode->data);

        }

        prevNode = currNode;
        currNode = currNode->next;

    }

}

/*
  Function:   cleanupRestaurant
   Purpose:   removes all dynamic memory from Resturant.
        in:   *r - ResturantType structure passed by reference (Resturant).
       out:   *r - ResturantType structure passed by reference (Resturant), now with no memory leaks.
*/
void cleanupRestaurant(RestaurantType *r) {

    cleanupResvList(&(r->reservations));
    cleanupPatronArray(&(r->patrons));
    
}
