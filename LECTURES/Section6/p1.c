#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *outfile;
    int count;
    int choice;

    printf("Write to stdout (1) or stdout(2)? ");
    scanf("%d",&choice);

    switch (choice) {
        case 1:
        outfile = stdout;
            break;

        case 2:
            outfile = fopen("dragons.txt", "w");
            if (!outfile) {
                printf("ciould not open file\n");
                exit(1);
            }
            break;

    }

    fprintf(stdout, "how many dragons" );
    fscanf(stdin, "%d", &count);
    fprintf(outfile, "%d dragons at Dragonstone\n", count);
    fclose(outfile);

}