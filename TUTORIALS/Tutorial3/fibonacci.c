#include <stdio.h>
int fibonacci_r(int);
int fibonacci_i(int);
int main () {
    printf("%d\n",fibonacci_r(10));
    printf("%d\n",fibonacci_i(10));

    return 0;
}


int fibonacci_r(int n) {
    if (n == 0) { return 0;}
    if (n ==1) {return 1;}

    else {
        return fibonacci_r(n-1) + fibonacci_r(n-2);
    }
}

int fibonacci_i(int n) {
    if (n == 0) { return 0;}
    if (n ==1) {return 1;}
    int a = 0;
    int b = 1;
    int result = 0;
    for (int i = 1; i < n; i++) {
        result = a + b;
        
        a = b;
        b = result;
    }
    return result;

    
}