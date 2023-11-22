#include "defs.h"

/*
  Function:  initResvList
   Purpose:   initizales Reservation List (ResvListType) structure.
       in:   *list - ResvListType passed by reference that is filled with garbage.
      out:   *list - ResvListType structre that is named initalized with default values.
*/
void initResvList(ResvListType *list) {

    list->head = NULL;
    list->nextId = RES_IDS;

}

/*
  Function:  initResvTime
   Purpose:   initizales ReservationTimeType structure with apporpiate date.
        in: **rt - pointer of ReservationTimeType structure passed by reference.
        in:   yr - int representing year.
        in:  mth - int representing month.
        in:  day - int representing day.
        in:   hr - int representing hr.
        in:  min - int representing min.
       out: **rt - pointer of ReservationTimeType structure with dynamically allocated memory aswell as a proper date.
*/
void initResvTime(ResvTimeType **rt, int yr, int mth, int day, int hr, int min) {

    *rt = malloc(sizeof(ResvTimeType));
    (*rt)->year = yr;
    (*rt)->month = mth;
    (*rt)->day = day;
    (*rt)->hours = hr;
    (*rt)->minutes = min;

}

/*
  Function:  initResv
   Purpose:   initizales ResvType structure with apporpiate date and associated to a Patron.
        in: **r  - pointer of ResvType structure passed by reference.
        in:   *p - PatronType passed by reference of a certain Patron
        in:  *rt - valid date ResvTimeType struct passed by reference.
       out: **r  - initialzed pointer to ResvType with valid date and Patron and default id.
*/
void initResv(ResvType **r, PatronType *p, ResvTimeType *rt) {

    *r = malloc(sizeof(ResvType));
    (*r)->patron = p;
    (*r)->resvTime = rt;
    (*r)->id = 0;

}

/*
  Function:  lessThan
   Purpose:   determines if r1's date is before r2.
        in: *r1  - pointer of ResvTimeType structure.
        in: *r2  - pointer of ResvTimeType structure.
    return: C_TRUE if r1 < r2, otherwise C_FALSE.
*/
int lessThan(ResvTimeType *r1, ResvTimeType *r2) {
    if (r1->year < r2->year) {

        return C_TRUE;

    }

    else if (r1->year > r2->year) {

        return C_FALSE;

    }

    else {

        if (r1->month < r2->month) {

            return C_TRUE;

        }

        else if (r1->month > r2->month) {

            return C_FALSE;

        } 

        else {

            if (r1->day < r2->day) {

                return C_TRUE;

            }

            else if (r1->day > r2->day) {

                return C_FALSE;

            }

            else {

                if (r1->hours < r2->hours) {

                    return C_TRUE;

                }

                else if (r1->hours > r2->hours) {

                    return C_FALSE;

                }

                else {

                    if (r1->minutes < r2->minutes) {

                        return C_TRUE;

                    }

                    else if (r1->minutes > r2->minutes) {

                        return C_FALSE;
                        
                    }

                    else {

                        return C_FALSE;

                    }

                }

            }

        }
    
    }
    
}

/*
  Function:  addResv
   Purpose:  adds reservation to ResvListType in accordance of earliest date
        in:  *list  - Reservation List.
        in:  *r     - new Resveration to add.
       out:  *list  - list with updated reservation.
*/
void addResv(ResvListType *list, ResvType *r) {
    NodeType* currNode = list->head; 
    NodeType* prevNode = NULL;

    NodeType* newNode = malloc(sizeof(NodeType));
    newNode->data = r;
    newNode->next = NULL;
    newNode->prev = NULL;

    while (currNode != NULL) {

        ResvTimeType* inList = currNode->data->resvTime;
        ResvTimeType* toAdd = newNode->data->resvTime;

        int swap = lessThan(toAdd, inList);

        if (swap == 1) {

            break;

        }

        else {

            prevNode = currNode;
            currNode = currNode->next;
        }

    }

    newNode->data->id = list->nextId;
    list->nextId++;

    if (prevNode == NULL) {

        list->head = newNode;

    }

    else {

        prevNode->next = newNode;
        newNode->prev  = prevNode;

    }

    newNode->next  = currNode;

    if (currNode != NULL) {

        currNode->prev = newNode;

    }

}

/*
  Function:  printReservation
   Purpose:  prints desired Reservation with date, id and Patron's name.
        in:  *r - ResvType structure of desired reservation.
*/
void printReservation(ResvType *r) {

    printf("%d  :: ", r->id);
    printf("%d-%02d-%02d ",r->resvTime->year, r->resvTime->month, r->resvTime->day);
    printf("@ %02d:%02d :: ", r->resvTime->hours, r->resvTime->minutes);
    printf("%s\n", r->patron->name);

}
/*
  Function:  printReservation
   Purpose:  prints all Reservations in ResvListType in both orders from earliest to latest as well as vice versa.
        in:  *list - ResvListType list of all Reservations.
*/
void printReservations(ResvListType *list) {

    NodeType *currNode = list->head;
    NodeType *prevNode = NULL;

    printf("FORWARD:\n");
    while (currNode != NULL) {

        printReservation(currNode->data);
        prevNode = currNode;
        currNode = currNode->next;

    }

    printf("BACKWARD:\n");
    currNode = prevNode;

    while (currNode != NULL) {

        printReservation(currNode->data);
        currNode = currNode->prev;

    }

}

/*
  Function:  cleanupResvList
   Purpose:  frees all Dynamically allocated memory in reservation list.
        in:  *list - ResvListType list of all Reservations.
       out: *list - ResvListType list of all Reservations, with no memory leaks.
*/
void cleanupResvList(ResvListType *list) {

  NodeType *currNode = list->head;
  NodeType *nextNode;

  while (currNode != NULL) {

    nextNode = currNode->next;
    free(currNode->data->resvTime);
    free(currNode->data);
    free(currNode);

    currNode = nextNode;
  }
}