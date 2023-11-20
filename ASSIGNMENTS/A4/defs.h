#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_OK            0
#define C_NOK          -1
#define C_TRUE          1
#define C_FALSE         0

#define MAX_STR        64
#define MAX_CAP       128

#define PATRON_IDS   1001
#define RES_IDS      4001

typedef struct {
  int   id;
  char  name[MAX_STR];
} PatronType;

typedef struct {
  int day;
  int month;
  int year;
  int hours;
  int minutes;
} ResvTimeType;

typedef struct {
  int           id;
  PatronType   *patron;
  ResvTimeType *resvTime;
} ResvType;

/*** Define the PatronArrayType here ***/

typedef struct{
  PatronType* elements;
  int size;
  int nextId;
} PatronArrayType;


/*** Define the NodeType here ***/

typedef struct Node{
  struct Node* next;
  struct Node* prev;
  ResvType* data;
} NodeType;


/*** Define the ResvListType here ***/

typedef struct  {
  NodeType* head;
  int nextId;
} ResvListType;

/*** Define the RestaurantType here ***/

typedef struct {
  char name[MAX_STR];
  ResvListType reservations;
  PatronArrayType patrons;
} RestaurantType;


void printMenu(int*);
void loadPatronData(RestaurantType*);
void loadResData(RestaurantType*);


