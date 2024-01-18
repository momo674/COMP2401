#include "defs.h"

/*
  Function:  runEscape
  Purpose:   Top-level function for the server process; initializes the escape, contains the game loop,
             handles escape result, and cleans up.
  Parameters:
    in:      None.
    out:     Server.
*/
void runEscape() {
  EscapeType escape;
  initEscape(&escape);

  while (!escapeIsOver(&escape)) {

    int birdSpawnProb = randomInt(10);

    if (birdSpawnProb <= 7 && escape.flyers.size < MAX_ARR) {

      int randomRow = randomInt(5);
      int randomCol = randomInt(MAX_COL);
      int randomStrength = randomInt(3) + 3;

      spawnFlyer(&escape, 'v', randomRow, randomCol, randomStrength);

    }

    int monkeySpawnProb = randomInt(10);
    if (monkeySpawnProb <= 3 && escape.flyers.size < MAX_ARR) {

      int randomRow = randomInt(MAX_ROW);
      int randomCol = randomInt(MAX_COL);
      int randomStrength = randomInt(4) + 8;

      spawnFlyer(&escape, '@', randomRow, randomCol, randomStrength);

    }

    moveHero(escape.heroes.elements[0], &escape);
    moveHero(escape.heroes.elements[1], &escape);

    for (int i = 0; i < escape.flyers.size; i++) {

      moveFlyer(escape.flyers.elements[i], &escape);

    }

    outputHollow(&escape);
  }

  outputHollow(&escape);

  handleEscapeResult(&escape);
  cleanupEscape(&escape);

}

/*
  Function:  initEscape
  Purpose:   Initializes the escape, including seeding PRNG, initializing the hero and flyer arrays,
             allocating and initializing both heroes, adding them to the heroes array,
             initializing sockets, and blocking until a client connection request is received.
  Parameters:
    in:      Pointer to the EscapeType structure.
    out:     Pointer to the EscapeType structure (init).
*/
void initEscape(EscapeType* escape) {
  escape->heroes.size = 0;
  escape->heroes.elements = malloc(2 * sizeof(HeroType));

  HeroType* Timmy;
  HeroType* Harold;

  int TimmyCol;
  int HaroldCol;

  while (1) {
    TimmyCol = randomInt(4);
    HaroldCol = randomInt(4);
    if (TimmyCol != HaroldCol) break;
  }

  initHero(&Timmy, 'T', TimmyCol, "Timmy");
  initHero(&Harold, 'H', HaroldCol, "Harold");

  addHero(&(escape->heroes), Timmy);
  addHero(&(escape->heroes), Harold);

  escape->flyers.size = 0;
  for (int i = 0; i < MAX_ARR; i++) {
    escape->flyers.elements[i] = NULL;
  }

  setupServerSocket(&(escape->listenSocket));
  printf("[SERVER] Waiting for connection...\n");
  acceptConnection(escape->listenSocket, &(escape->viewSocket));
  printf("[SERVER] Client connected!\n");

}

/*
  Function:  escapeIsOver
  Purpose:   Determines if both heroes are dead or have escaped.
  Parameters:
    in:      Pointer to the EscapeType structure.
    out:     C_TRUE if escape is over, C_FALSE otherwise.
*/
int escapeIsOver(EscapeType* escape) {
  int harold_done = C_FALSE;
  int timmy_done = C_FALSE;

  if (escape->heroes.elements[0]->health == 0 || escape->heroes.elements[0]->partInfo.pos.col == 999) {
    timmy_done = C_TRUE;
  }

  if (escape->heroes.elements[1]->health == 0 || escape->heroes.elements[1]->partInfo.pos.col == 999) {
    harold_done = C_TRUE;
  }

  return (harold_done && timmy_done);
}

/*
  Function:  handleEscapeResult
  Purpose:   Prints out and sends to the client the outcome of the escape.
  Parameters:
    in:      Pointer to the EscapeType structure.
    out:     closed server.
*/
void handleEscapeResult(EscapeType* escape) {
  char timStat[MAX_STR] = "";

  if (escape->heroes.elements[0]->health == 0) {
    strcpy(timStat, "Timmy IS DEAD...\n");
  } else {
    strcpy(timStat, "Timmy ESCAPED !!!\n");
  }

  char harStat[MAX_STR];
  if (escape->heroes.elements[1]->health == 0) {
    strcpy(harStat, "Harold IS DEAD...\n");
  } else {
    strcpy(harStat, "Harold ESCAPED !!!\n");
  }

  printf("%s", timStat);
  printf("%s", harStat);
  sendData(escape->viewSocket, timStat);
  sendData(escape->viewSocket, harStat);

  close(escape->viewSocket);
  close(escape->listenSocket);

}

/*
  Function:  cleanupEscape
  Purpose:   Cleans up escape, including deallocating required memory, sending termination
             (quit) message to the client, and closing sockets.
  Parameters:
    in:      Pointer to the EscapeType structure.
    out:     None.
*/
void cleanupEscape(EscapeType* escape) {
  free(escape->heroes.elements[0]);
  free(escape->heroes.elements[1]);
  free(escape->heroes.elements);

  for (int i = 0; i < MAX_ARR; i++) {

    if (escape->flyers.elements[i] != NULL) {
      free(escape->flyers.elements[i]);
    }

  }

}
