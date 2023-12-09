#include "defs.h"

/*
  Function:  initHero
  Purpose:   Dynamically allocates and initializes one hero.
  Parameters:
    in:      Pointer to the HeroType pointer, hero's avatar, initial position, and name.
    out:     Initialized HeroType structure.
*/
void initHero(HeroType** hero, char avatar, int pos, char* name) {
    *hero = malloc(sizeof(HeroType));
    strcpy((*hero)->name, name);
    (*hero)->dead = C_FALSE;
    (*hero)->health = 20;
    (*hero)->partInfo.avatar = avatar;
    (*hero)->partInfo.pos.col = pos;
    (*hero)->partInfo.pos.row = MAX_ROW - 1;
}

/*
  Function:  addHero
  Purpose:   Adds hero to escape's hero collection.
  Parameters:
    in:      Pointer to the HeroArrayType structure and the hero to be added.
    out:     Array with extra hero.
*/
void addHero(HeroArrayType* array, HeroType* hero) {
    array->elements[array->size] = hero;
    array->size++;
}

/*
  Function:  moveHero
  Purpose:   Computes hero's next move in accordance to instruction 3.4 and updates hero's position.
  Parameters:
    in:      Pointer to the HeroType structure and the EscapeType structure.
    out:     escape with updated index of hero.
*/
void moveHero(HeroType* hero, EscapeType* escape) {
    if (hero->partInfo.avatar == '+') {
        return;
    }
    if (hero->partInfo.pos.col == 999) {
        return;
    }
    if (hero->partInfo.avatar == 'T') {
        int timmyProb = randomInt(10);
        int move = 0;

        if (timmyProb == 0 || timmyProb == 1) {
            move++;
        } else if (timmyProb >= 2 && timmyProb <= 4) {
            move--;
        } else {
            move += 2;
        }

        int newPos = hero->partInfo.pos.col;
        newPos += move;

        if (newPos > MAX_COL) {
            newPos = 999;
        }

        if (newPos < 0) {
            newPos = 0;
        }

        hero->partInfo.pos.col = newPos;
        escape->heroes.elements[0]->partInfo.pos.col = newPos;
    } else if (hero->partInfo.avatar == 'H') {
        int haroldProb = randomInt(10);
        int move = 0;

        if (haroldProb == 2) {
            move += 5;
        } else if (haroldProb == 3) {
            move -= 4;
        } else if (haroldProb == 4 || haroldProb == 5) {
            move -= 2;
        } else {
            move += 3;
        }

        int newPos = hero->partInfo.pos.col;
        newPos += move;

        if (newPos > MAX_COL) {
            newPos = 999;
        }

        if (newPos < 0) {
            newPos = 0;
        }

        hero->partInfo.pos.col = newPos;
        escape->heroes.elements[1]->partInfo.pos.col = newPos;
    }
}

/*
  Function:  heroIsSafe
  Purpose:   Determines if a hero has successfully escaped the Hollow.
  Parameters:
    in:      Pointer to the HeroType structure.
    out:     C_TRUE if the hero has successfully escaped, C_FALSE otherwise.
*/
int heroIsSafe(HeroType* hero) {
    if (hero->partInfo.pos.col == 999) return C_TRUE;
    else return C_FALSE;
}
