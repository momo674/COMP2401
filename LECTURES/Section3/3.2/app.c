#include <stdio.h>
#include <stdlib.h>

int main() {
    char* block = malloc(20*sizeof(char));
    

    *block = 1;
    block[1] = 2;

    char* block_2 = block + 2;

    block_2[1] = 4;

    for (int i = 0; i < 20; i ++) {
        printf("block points to: %d\n", *(block+i));
    }
    
}