#include "defs.h"

/*
  Function:  spawnFlyer
  Purpose:   Dynamically allocates and initializes one flyer, and adds it to the escape's flyer collection.
  Parameters:
    in:      Pointer to the EscapeType structure, flyer's avatar, row, column, and strength.
    out:     new flyer to array.
*/
void spawnFlyer(EscapeType* escape, char avatar, int row, int col, int strength) {
   FlyerType* flyer = (FlyerType*) malloc(sizeof(FlyerType));
   flyer->strength = strength;
   flyer->partInfo.avatar = avatar;
   flyer->partInfo.pos.col = col;
   flyer->partInfo.pos.row = row;
   addFlyer(&(escape->flyers), flyer);
}

/*
  Function:  addFlyer
  Purpose:   Adds a flyer to the escape's flyer collection.
  Parameters:
    in:      Pointer to the FlyerArrayType structure, and the flyer to be added.
    out:     array with new flyer.
*/
void addFlyer(FlyerArrayType* array, FlyerType* flyer) {
   for (int i = 0; i < MAX_ARR; i++) {
      if (array->elements[i] == NULL) {
         array->elements[i] = flyer;
         array->size++;
         break;
      }
   }
}

/*
  Function:  moveFlyer
  Purpose:   Computes the flyer's next move, updates the flyer's position, and deals with collisions with heroes.
  Parameters:
    in:      Pointer to the FlyerType structure and the EscapeType structure.
    out:     updated posistion for flyer.
*/
void moveFlyer(FlyerType* flyer, EscapeType* escape) {
   if (flyer == NULL) {
      return;
   }
   if (flyerIsDone(flyer) == C_TRUE) {
      for (int i = 0; i < escape->flyers.size; i++) {
         if (escape->flyers.elements[i] == NULL) {
            continue;
         }
         if ((escape->flyers.elements[i]->partInfo.pos.row == flyer->partInfo.pos.row) &&
             (escape->flyers.elements[i]->partInfo.pos.col == flyer->partInfo.pos.col) &&
             (escape->flyers.elements[i]->partInfo.avatar == flyer->partInfo.avatar)) {
            free(escape->flyers.elements[i]);
            escape->flyers.elements[i] = NULL;
            escape->flyers.size--;
            return;
         }
      }
   }
   if (flyer->partInfo.avatar == 'v') {

      int randVal = randomInt(3);
      int newCol = flyer->partInfo.pos.col;
      int newRow = flyer->partInfo.pos.row + 1;

      if (randVal == 0) {
         newCol++;
      } else if (randVal == 1) {
         newCol--;
      }

      if (newCol > MAX_COL - 1) {
         newCol = MAX_COL - 1;
      } else if (newCol < 0) {
         newCol = 0;
      }

      if (newRow < 0) {
         newRow = 0;
      }

      if (newRow > MAX_ROW - 1) {
         newRow = MAX_ROW - 1;
      }
      flyer->partInfo.pos.row = newRow;
      flyer->partInfo.pos.col = newCol;

      HeroType* hero_to_damage = checkForCollision(&(flyer->partInfo.pos), escape);

      if (hero_to_damage != NULL) incurDamage(hero_to_damage, flyer);
      return;

   }

   if (flyer->partInfo.avatar == '@') {

      int randomVal = randomInt(7);
      int newRow = randomVal - 3 + flyer->partInfo.pos.row;
      if (newRow < 0) {
         newRow = 0;
      }
      if (newRow > MAX_ROW - 1) {
         newRow = MAX_ROW - 1;
      }

      int change = 0;
      computeHeroDir(escape, flyer, &change);
      int newCol = flyer->partInfo.pos.col + change;
      if (newCol < 0) newCol = 0;
      flyer->partInfo.pos.row = newRow;
      flyer->partInfo.pos.col = newCol;

      HeroType* hero_to_damage = checkForCollision(&(flyer->partInfo.pos), escape);

      if (hero_to_damage != NULL) incurDamage(hero_to_damage, flyer);
      return;

   }
}

/*
  Function:  computeHeroDir
  Purpose:   Computes the direction (-1 for left, +1 for right, 0 for same) of the closest hero
             that is still alive and participating; direction is returned using the parameter.
  Parameters:
    in:      Pointer to the EscapeType structure, Pointer to the FlyerType structure, and a pointer to the change variable.
    out:     change value updated.
*/
void computeHeroDir(EscapeType* escape, FlyerType* flyer, int* change) {
   int timCol = (escape->heroes.elements[0]->dead) ? (-999) : (escape->heroes.elements[0]->partInfo.pos.col);
   int harCol = (escape->heroes.elements[1]->dead) ? (-999) : (escape->heroes.elements[1]->partInfo.pos.col);
   int flyCol = flyer->partInfo.pos.col;
   int timFly = abs(flyCol - timCol);
   int harFly = abs(flyCol - harCol);

   int closest = (timFly > harFly) ? (harCol) : (timCol);

   if (closest == flyCol) return;

   *change = (closest < flyCol) ? (-1) : (1);

}

/*
  Function:  flyerIsDone
  Purpose:   Determines if a flyer has reached the ground.
  Parameters:
    in:      Pointer to the FlyerType structure.
    out:     C_TRUE if the flyer has reached the ground, C_FALSE otherwise.
*/
int flyerIsDone(FlyerType* flyer) {
   if (flyer->partInfo.pos.row == MAX_ROW - 1) {
      return C_TRUE;
   }
   return C_FALSE;
}

/*
  Function:  checkForCollision
  Purpose:   Checks if a flyer with the given position has collided with a hero and returns that hero as the return value (NULL if no collision).
  Parameters:
    in:      Pointer to the PositionType structure and pointer to the EscapeType structure.
    out:     Pointer to the HeroType structure if there is a collision, NULL otherwise.
*/
HeroType* checkForCollision(PositionType* pos, EscapeType* escape) {
   int row = pos->row;
   int col = pos->col;

   int timmy_row = escape->heroes.elements[0]->partInfo.pos.row;
   int timmy_col = escape->heroes.elements[0]->partInfo.pos.col;

   int harold_row = escape->heroes.elements[1]->partInfo.pos.row;
   int harold_col = escape->heroes.elements[1]->partInfo.pos.col;

   if (row == timmy_row && col == timmy_col) {
      return escape->heroes.elements[0];
   } else if (row == harold_row && col == harold_col) {
      return escape->heroes.elements[1];
   } else {
      return NULL;
   }
}

/*
  Function:  incurDamage
  Purpose:   Decreases hero's health by the flyer's strength (if health gets negative, reset to 0);
             if hero dies, its avatar is changed.
  Parameters:
    in:      Pointer to the HeroType structure and pointer to the FlyerType structure.
    out:     None.
*/
void incurDamage(HeroType* hero, FlyerType* flyer) {
   hero->health -= flyer->strength;
   if (hero->health <= 0) {
      hero->health = 0;
      hero->dead = 1;
      hero->partInfo.avatar = '+';
   }
}