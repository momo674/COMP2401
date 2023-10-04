#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_ROW       15
#define MAX_COL       60
#define MAX_BIRDS    128
#define BIRD_FREQ     90

#define C_TRUE         1
#define C_FALSE        0

void initHollow(char[MAX_ROW][MAX_COL]); 
void printHollow(char[MAX_ROW][MAX_COL]); 
char escapeOver(char, char, int, int);
char isDone(char, int);
int  moveHero(char, int, char[MAX_ROW][MAX_COL]); 
void moveBird(int, int[MAX_BIRDS], int[MAX_BIRDS], char[MAX_ROW][MAX_COL]); 
void moveInHollow(char, int, int, int, int, char[MAX_ROW][MAX_COL]); 
void printResult(char, char, int, int); 
int  randomInt(int);

int main(){

  srand( (unsigned)time( NULL ) );
  char hollow[MAX_ROW][MAX_COL];
  
  int bird_row[MAX_BIRDS];
  int bird_col[MAX_BIRDS];
  

  for (int i = 0; i < MAX_BIRDS;i++) {
    bird_row[i] = -1;
    bird_col[i] = -1;
  }
  
  initHollow(hollow);
  printHollow(hollow);
  
  int h_index = 0;
  int t_index = 0;
  char h_done = 0;
  char t_done = 0;
  char h_dead = 0;
  char t_dead = 0;

  while (!escapeOver(hollow[MAX_ROW-1][t_index], hollow[MAX_ROW-1][h_index], t_index, h_index)) {
    if (hollow[MAX_ROW-1][h_index] == 'v') {

      hollow[MAX_ROW-1][h_index] = '+';
      h_done = 1;
      h_dead = 1;

    }

    if (hollow[MAX_ROW-1][t_index] == 'v') {

      hollow[MAX_ROW-1][t_index] = '+';
      t_done = 1;
      t_dead = 1;

    }

    if (h_dead) {

      hollow[MAX_ROW-1][h_index] = '+';

    }

    if (t_dead) {

      hollow[MAX_ROW-1][t_index] = '+';

    }
    
    int t_next = moveHero('T',t_index,hollow);
    if (!t_done){

      if (t_next < 0) {

        t_next = 0;

      }

      moveInHollow('T', MAX_ROW-1, t_index, MAX_ROW-1, t_next, hollow);
      t_index = t_next;

    }
      
    int h_next = moveHero('H',h_index,hollow);

    if (!h_done){

      if (h_next < 0) {

        h_next = 0;

      }

      moveInHollow('H', MAX_ROW-1, h_index, MAX_ROW-1, h_next, hollow);
      h_index = h_next;

    }

    if (t_index > MAX_COL - 1) {

        t_done = 1;

    }

    if (h_index > MAX_COL - 1) {
        
        h_done = 1;
        
    }
     
    int bird_prob = randomInt(10);

    if (bird_prob < 9) {

        for (int bird = 0; bird < MAX_BIRDS; bird++) {

            if (bird_row[bird] == -1 || bird_col[bird] == -1) {

                bird_row[bird] = 0;
                bird_col[bird] = randomInt(MAX_COL-1);
                break;

            }

        }

    }

    for (int index = 0; index < MAX_BIRDS; index++) {
      
      int old_row = bird_row[index];
      int old_col = bird_col[index];

      if (old_col>=0 && old_col <= MAX_COL-1 && old_row >= 0 && old_row <= MAX_ROW-1){
        
        moveBird(index, bird_row, bird_col, hollow);

        int new_row = bird_row[index];
        int new_col = bird_col[index];

        moveInHollow('v', old_row, old_col, new_row , new_col , hollow);
       
      }
      
    }

    if (hollow[MAX_ROW-1][h_index] == 'v') {

      hollow[MAX_ROW-1][h_index] = '+';
      h_done = 1;
      h_dead = 1;

    }

    if (hollow[MAX_ROW-1][t_index] == 'v') {

      hollow[MAX_ROW-1][t_index] = '+';
      t_done = 1;
      t_dead = 1;

    }

    if (h_dead) {

      hollow[MAX_ROW-1][h_index] = '+';

    }

    if (t_dead) {

      hollow[MAX_ROW-1][t_index] = '+';

    }

    usleep(300000);
    system("clear");
    printHollow(hollow);
  }
  
  printResult(hollow[MAX_ROW-1][t_index], hollow[MAX_ROW-1][h_index], t_index, h_index);
   
  return 0;
  
}
  
/*
  Function:  randomInt
  Purpose:   returns a random number in the range [0,max)
  Parameters:
    in:      maximum of range
    return:  randomly generated number
*/
int randomInt(int max)
{
  return(rand() % max);
}

/*
  Function:  initHollow
  Purpose:   initializes hollow array, remvoes all garbage and places in 0's
  Parameters:
    in:      hollow array (with garbage inside)
    out:     hollow array (with 0's inside)
*/
void initHollow(char hollow[MAX_ROW][MAX_COL]) {
  for (int i = 0 ; i < MAX_ROW; ++i) {
    for (int j = 0; j < MAX_COL; ++j) {
        hollow [i][j] = 0;
    }
  }
}

/*
  Function:  printHollow
  Purpose:   prints the hollow in console as a desired game display
  Parameters:
    in:      hollow array
    out:     specific display for hollow in console
*/
void printHollow(char hollow[MAX_ROW][MAX_COL]) {

  for (int outside_border = 0; outside_border <= MAX_COL; outside_border++) {

    if (outside_border % 2 == 0) {

        printf("-");

    }
    else{

        printf("-");

    }

  }

  printf("-");
  printf("\n");

  for (int i = 0 ; i < MAX_ROW; ++i) {

    if (i == MAX_ROW - 1) {

        printf("=");

    }

    else {

        printf("|");

    }
    
    for (int j = 0; j < MAX_COL; ++j) {
        
        char x  = hollow[i][j];
        
        if (x == 0){

            x = ' ';
          
        }
        
        if (j+1 > MAX_COL) {

            printf("%c\n", x);

        }

        else{

            printf("%c", x);

        }

    }

    if (i == MAX_ROW - 1) {

        printf("=\n");

    }

    else {

        printf("|\n");

    }

  }
  for (int outside_border = 0; outside_border <= MAX_COL; outside_border++) {

    if (outside_border % 2 == 0) {

        printf("-");

    }
    else{

        printf("-");
        
    }

  }

  printf("-");
  printf("\n");
 
}

/*
  Function:  moveInHollow
  Purpose:   moves a specific character in hollow array to new index
  Parameters:
    in:      specific character, old row number, old colum number, new row number, new column number, hollow array
    out:     hollow array with specific character at new location.
*/
void moveInHollow(char avatar, int oldRow, int oldCol, int newRow, int newCol, char hollow[MAX_ROW][MAX_COL]) {
  
  if ((avatar == 'H' || avatar == 'T') && newCol > MAX_COL - 1) {

    hollow[oldRow][oldCol] = 0;
    return;

  }

  hollow[oldRow][oldCol] = 0;
  hollow[newRow][newCol] = avatar;

}

/*
  Function:  moveHero
  Purpose:   calculates and returns a new column for the hero to reside in
  Parameters:
    in:      avatar character, old column index, hollow array.
    return:  new column integer

*/
int moveHero(char avatar, int oldPos, char hollow[MAX_ROW][MAX_COL]) {

  int x = randomInt(10);
  int newPos;

  if (avatar == 'T') {

    if (0<=x && x<=4) { 
      
        newPos = oldPos + 3;

    }

    else if (x == 5 || x == 6) { 
        
        newPos = oldPos + 2;

    }

    else { 
     
        newPos = oldPos - 1;

    }

    if (newPos < 0) {

        newPos = 0;

    }
    
    return newPos;

  }

  else if (avatar == 'H') {

    if (x == 0) { 
        
        newPos = oldPos + 6;
    
    }

    else if (x == 1) {
      
        newPos = oldPos - 4;


    }

    else if (2<=x && x<=5) {
    
        newPos = oldPos + 4;

    }

    else if (x == 6 || x == 7) {
      
        newPos = oldPos - 2;

    }

    else {
        
        newPos = oldPos;

    }
    
    if (newPos < 0) {

        newPos = 0;

    }
    
    return newPos;

  }
  
  return -1;
  
}

/*
  Function:  moveBird
  Purpose:   calculates and adds a new index for a bird to it's parallel arrays.
  Parameters:
    in:      index identifying specific bird, array for both rows and columns, array for hollow.
    out:     parallel arrays (row array and column array) with updated values at every index.
*/
void moveBird(int index, int rows[MAX_BIRDS], int cols[MAX_BIRDS], char hollow[MAX_ROW][MAX_COL]){
  
  int row_prob = randomInt(2);
  int col_prob = randomInt (3);
  int new_row = rows[index];
  int new_col = cols[index];
  
  if (rows[index] == MAX_ROW - 1) {
    
    rows[index] = -1;
    cols[index] = -1;

    if (hollow[rows[index]][cols[index]] == 'H' ||hollow[rows[index]][cols[index]] == 'T') {

        hollow[rows[index]][cols[index]] = '+';

    }

    else {

        hollow[rows[index]][cols[index]] = 0;

    }

    return;
    
  }

  
  if (row_prob == 0) {

    new_row = rows[index] + 1;

  }

  else if (row_prob == 1) {

    new_row = rows[index] + 2;

  }

  if (col_prob == 0) {

    new_col = cols[index] - 1;

  }

  else if (col_prob == 1) {

    new_col = cols[index] + 1;

  }

  else if (col_prob == 2) {

    new_col = cols[index];

  }

  if (new_row > MAX_ROW - 1) {

    new_row = MAX_ROW - 1;
    
  }

  if (new_row < 0) {

    new_row = 0;

  }

  if (new_col > MAX_COL - 1) {

    new_col = MAX_COL - 1;

  }

  if (new_col < 0) {

    new_col = 0;

  }
  
  rows[index] = new_row;
  cols[index] = new_col;
  
}

/*
  Function:  isDone
  Purpose:   returns C_TRUE (1) if a is done playing, else returns C_FALSE (0)
  Parameters:
    in:      Avatar character, column of hero
    return:     C_TRUE(1) or C_FALSE(0)
*/
char isDone(char avatar, int index) {

  if (index > MAX_COL || avatar == '+') {

    return C_TRUE;

  }

  return C_FALSE;

}

/*
  Function:  escapeOver
  Purpose:   returns C_TRUE (1) if the escape is over, else returns C_FALSE (0)
  Parameters:
    in:      Timmy Avatar character, Harold Avatar character, column of Timmy, column of Harold
    return:     C_TRUE(1) or C_FALSE(0)
*/
char escapeOver(char tAvatar, char hAvatar, int tCol, int hCol){
    
    char tdone = 0;
    char hdone = 0;

    if (tAvatar == '+' || tCol > MAX_COL -1) {

        tdone = 1;

    }
    
    if (hAvatar == '+' || hCol > MAX_COL -1) {

        hdone = 1;

    }

    if (tdone == 1 && hdone == 1) {

        return C_TRUE;

    }

    return C_FALSE;

}

/*
  Function:  printResult
  Purpose:   prints the result of escape game in console.
  Parameters:
    in:      Timmy Avatar character, Harold Avatar character, column of Timmy, column of Harold
    out:     resulting message 
*/
void printResult(char tAvatar, char hAvatar, int tCol, int hCol) {
    
    char t_dead = 0;
    char t_escaped = 0;
    char h_dead = 0;
    char h_escaped = 0;

    if (tAvatar == '+') {

        t_dead = 1;
        t_escaped = 0;
    }

    else if (tCol > MAX_COL -1) {

        t_escaped = 1;
        t_dead = 0;

    }

    if (hAvatar == '+') {

        h_dead = 1;
        h_escaped = 0;

    }

    else if (hCol > MAX_COL -1) {

        h_escaped = 1;
        h_dead = 0;

    }

    if (t_dead && h_dead) {

        printf("BOTH HEROS HAVE DIED!\n");

    }

    else if (t_escaped && h_escaped) {

        printf("BOTH HEROS HAVE ESCAPED!\n");

    }

    else {

        if (h_dead) {

            printf("Harold dies, but");

        }

        else if (h_escaped) {

            printf("Harold escapes, but");

        }

        if (t_dead) {

            printf(" Timmy dies...\n");

        }
        else if (t_escaped) {

            printf(" Timmy escaped...\n");

        }
        
    }

}