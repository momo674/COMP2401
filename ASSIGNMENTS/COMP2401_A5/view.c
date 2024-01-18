#include "defs.h"

/*
  Function:  outputHollow
  Purpose:   Top-level function for serializing hollow, printing, and sending it to the client.
  Parameters:
    in:      EscapeType structure representing the game state.
    out:     None.
*/
void outputHollow(EscapeType* escape) {
  
    char buffer[MAX_BUFF];
    for (int i = 0; i < MAX_BUFF; i++) {
        buffer[i] = 0;
    }
    serializeHollow(escape, buffer);
          
    usleep(300000);
    system("clear");
    printf("%s", buffer);
    sendData(escape->viewSocket, buffer);
}

/*
  Function:  initHollow
  Purpose:   Initializes a 2D grid with participant avatars in their current positions.
  Parameters:
    in:      EscapeType structure representing the game state.
            2D array to represent the hollow.
    out:     initilizaed hollow.
*/
void initHollow(EscapeType* escape, char hollow[][MAX_COL]) {

    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            hollow[i][j] = 0;
        }
    }

    hollow[escape->heroes.elements[0]->partInfo.pos.row][escape->heroes.elements[0]->partInfo.pos.col] = escape->heroes.elements[0]->partInfo.avatar;
    hollow[escape->heroes.elements[1]->partInfo.pos.row][escape->heroes.elements[1]->partInfo.pos.col] = escape->heroes.elements[1]->partInfo.avatar;

    for (int i = 0; i < escape->flyers.size - 1; i++) {
        if (escape->flyers.elements[i] != NULL) {
            hollow[escape->flyers.elements[i]->partInfo.pos.row][escape->flyers.elements[i]->partInfo.pos.col] = escape->flyers.elements[i]->partInfo.avatar;
        }
    }
}

/*
  Function:  serializeHollow
  Purpose:   Constructs a 1D array with formatted Hollow output, containing all avatars in their positions,
             with borders, spacing, and newlines.
  Parameters:
    in:      EscapeType structure representing the game state.
            1D array to store the formatted Hollow output.
    out:    1d ARRAY (out by parameter).
*/
void serializeHollow(EscapeType* escape, char* buffer) {

    char hollow[MAX_ROW][MAX_COL];
    initHollow(escape, hollow);

    for (int outside_border = 0; outside_border <= MAX_COL; outside_border++) {

        if (outside_border % 2 == 0) {
            strcat(buffer, "-");
        }
        else {
            strcat(buffer, "-");
        }
    }

    strcat(buffer, "-\n");

    for (int i = 0; i < MAX_ROW; ++i) {

        if (i == MAX_ROW - 1) {
            strcat(buffer, "=");
        }
        else {
            strcat(buffer, "|");
        }

        for (int j = 0; j < MAX_COL; ++j) {
            char x = hollow[i][j];

            if (x == 0) {
                x = ' ';
            }

            int length = strlen(buffer);

            if (j + 1 > MAX_COL) {
                buffer[length] = x;
                buffer[length + 1] = '\0';
                strcat(buffer, "\n");
            }
            else {
                buffer[length] = x;
                buffer[length + 1] = '\0';
            }
        }

        if (i == MAX_ROW - 1) {
            char format[MAX_STR];
            sprintf(format, "=   Harold: %d\n", escape->heroes.elements[1]->health);
            strcat(buffer, format);
        }
        else {
            if (i == MAX_ROW - 2) {
                char format[MAX_STR];
                sprintf(format, "|   Timmy: %d\n", escape->heroes.elements[0]->health);
                strcat(buffer, format);
            }
            else {
                strcat(buffer, "|\n");
            }
        }
    }

    for (int outside_border = 0; outside_border <= MAX_COL; outside_border++) {
        if (outside_border % 2 == 0) {
            strcat(buffer, "-");
        }
        else {
            strcat(buffer, "-");
        }
    }

    strcat(buffer, "-\n");
}

/*
  Function:  setPos
  Purpose:   Sets a participant's position to the given row/col, with values reset to the closest edge if outside of range.
  Parameters:
    in:      Pointer to a PositionType structure representing the participant's position.
            New row and column values.
    out:      Pointer to updated pos.
*/
void setPos(PositionType* pos, int row, int col) {
    if (row > MAX_ROW - 1) {
        row = MAX_ROW - 1;
    }

    if (row < 0) {
        row = 0;
    }

    if (col > MAX_COL - 1) {
        col = MAX_COL - 1;
    }

    if (col < 0) {
        col = 0;
    }

    pos->col = col;
    pos->row = row;
}
