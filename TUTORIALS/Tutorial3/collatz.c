#include <stdio.h>
void collatz(int);
int main () {
    collatz(101);
    return 0;
}



void collatz(int n) {
    do {
        printf("%d\n", n);
        n = (n%2 == 0) ? (n/2) : (3*n + 1);
        
    }
    while (n!=1);
}