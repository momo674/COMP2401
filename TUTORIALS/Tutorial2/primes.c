#include <stdio.h>

void primes (int n);



int main() {

	primes(100);

}



void primes (int n) {
	
	if (n != 1 && n != 0) {
		
			for (int i = 1; i < n; i++) {
				for (int j = 2; j < n; j++) {
					if (i%j == 0) {
						break;
					}
					else {printf("%d\n",i); break;}
				}
			}
		
		}
	}
	

