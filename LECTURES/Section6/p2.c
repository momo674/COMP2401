#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *infile;
    char text[80];
    int count, numBytes;

    infile = fopen ("dragons.txt", "r");
    if (!infile) {
        printf("coudl not read file.\n");
        exit(1);
    }
    fscanf(infile, "%d %s", &count, text);
    fclose(infile);

    printf("\n with fscnaf: %d %s\n", count, text);

    infile = fopen ("dragons.txt", "r");
    if (!infile) {
        printf("coudl not read file.\n");
        exit(1);
    }

    numBytes = fread(text, 1, 80, infile);
    text[numBytes] = '\0';
    fclose(infile);

    printf("\n with fread: %s\n", text);

}