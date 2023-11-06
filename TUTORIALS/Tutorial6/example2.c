#include <stdio.h>
#include <stdlib.h>

void convertToOct(int, char*);

int main() {
	int n;
	char digits[6];
	printf("Enter an integer number:");
	scanf("%d", &n);
	printf("Decimal = %d\n", n);
	convertToOct(n, digits);
	int i;
	printf("Octal = 0");
	for (i = sizeof(digits); i > 0; i--) {
		printf("%d", digits[i-1]);
	}
	printf("\n");
	return 0;
}

void convertToOct(int n, char *d) {
	int c = 0;
	while (n > 0) {
		d[c] = '0' + n % 8;
		n = n / 8;
		c++;
	}
}
