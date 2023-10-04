#include <stdio.h>
void non_primes(int);
int main () {
    non_primes(100);
    return 0;
}

void non_primes(int n) {
    for (int i = 2; i < n; i++) {
        int prime = 1;
        for (int j = 2; j < i; j++) {
            if (i%j == 0) {
                prime = 0;
                break;
            }
            
        }
        if (!prime) {
            printf("%d\n", i);
        }
        
    }
}

