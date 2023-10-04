#include <stdio.h>
void divisors(int);


int main () {
    divisors(100);
    return 0;
}

void divisors(int n) {
    int i = 1;
    while (i <= n) {
        if (n%i==0) {
            printf("%d\n", i);
            ++i;
        }
        else {
            ++i;
            continue;
        }
    } 
}
