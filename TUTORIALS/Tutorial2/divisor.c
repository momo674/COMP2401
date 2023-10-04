#include <stdio.h>

//Preprocessing our function.
int gcd(int a, int b);

/*
    Function: main function of program, runs our code
*/
int main() {
    int x = gcd(20, 8);
	printf("%d", x);

}


/*
    Function: Calculates the Greatest Common Denominator
    Input: Two input parameters integers
    Output: A single int output parameter
*/
int gcd(int a, int b)

{
    int gcd = 0;
	for (int i = 1; i<= a && i<= b; ++i ) {
        if (a%i==0 && b%i==0){
            gcd = i;
        }
    }

	return gcd;
}
