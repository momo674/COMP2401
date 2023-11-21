#include <stdio.h>
#include <string.h>

#include "defs.h"

int main()
{
  RestaurantType local;
  initRestaurant(&local, "Christine's Bistro");
  loadPatronData(&local);
  loadResData(&local);
  int choice = -1;
  printMenu(&choice);

  while (choice != 0) {
    if (choice == 1) {
      printf("REGISTERED PATRONS AT %s:\n", local.name);
      printPatrons(&(local.patrons));
      choice = -1;
    }

    else if (choice == 2) {
      printReservations(&(local.reservations));
      choice = -1;
    }

    else if (choice == 3) {
      int id = -1;
      printf("Enter patron id: ");
      scanf("%d", &id);
      printResByPatron(&local, id);
      choice = -1;
    }

    choice = -1;
    printMenu(&choice);

  }  
  cleanupRestaurant(&local);
  return 0;
}

void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print patrons\n");
  printf("  (2) Print reservations\n");
  printf("  (3) Print reservations by patron\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  if (c == 1) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}

