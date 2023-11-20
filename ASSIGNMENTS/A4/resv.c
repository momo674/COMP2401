#include "defs.h"
void initResvList(ResvListType *list) {
    list->head = NULL;
    list->nextId = RES_IDS;
}

void initResvTime(ResvTimeType **rt, int yr, int mth, int day, int hr, int min) {
    *rt = malloc(sizeof(ResvTimeType));
    (*rt)->year = yr;
    (*rt)->month = mth;
    (*rt)->day = day;
    (*rt)->hours = hr;
    (*rt)->minutes = min;
}

void initResv(ResvType **r, PatronType *p, ResvTimeType *rt) {
    *r = malloc(sizeof(ResvType));
    (*r)->patron = p;
    (*r)->resvTime = rt;
    (*r)->id = 0;
}

/*
    returns true if r1 begins before than r2
    if r1->year, r1
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

void addResv(ResvListType *list, ResvType *r) {
    NodeType* currNode = list->head; 
    NodeType* prevNode = NULL;

    NodeType* newNode = malloc(sizeof(NodeType));
    newNode->data = r;
    newNode->next = NULL;
    newNode->prev = NULL;

    while (currNode != NULL) {

        ResvTimeType* inList = currNode->data->resvTime;
        ResvListType* toAdd = newNode->data->resvTime;

        int swap = lessThan(toAdd, inList);

        if (swap == 0) {
            break;
        }
        else {
            prevNode = currNode;
            currNode = currNode->next;
        }
    }

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

void printReservation(ResvType *r) {
    //add padding for zero at day,month, minutes, hours
    //ex. 8 should be 08
    printf("%d  :: ", r->id);
    printf("%d-%d-%d ",r->resvTime->year, r->resvTime->month, r->resvTime->day);
    printf("@ %d:%d :: ", r->resvTime->hours, r->resvTime->minutes);
    printf("%s\n", r->patron->name);
}

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

void cleanupResvList(ResvListType *list) {
  NodeType *currNode = list->head;
  NodeType *nextNode;

  while (currNode != NULL) {
    nextNode = currNode->next;

    free(currNode->data);
    free(currNode);

    currNode = nextNode;
  }