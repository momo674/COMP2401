#include <stdio.h> 
void calculate();
int main () {
    calculate();
    return 0;
}

void calculate() {
    int input = 0;
    int sum = 0;
    int max = 0;
    int min = 99999;
    int avg = 0;
    int count = 0;

    do {
        if (input == -1) {break;}
        printf("Enter your number: \n");
        scanf("%d\n", &input);
        sum+=input;

        if (input>max) {
            max = input;
        }

        if (input < min) {
            min = input;
        }

        count ++;
        

    }
    while (input != -1);

    printf("sum: %d\n", sum);
    printf("max: %d\n", max);
    printf("min: %d\n", min);
    printf("avg: %d\n", sum/count);
}