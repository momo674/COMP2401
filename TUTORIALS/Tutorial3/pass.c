#include <stdio.h>

void passFail();

int main() {

  passFail();

}

void passFail() {
  char p;
  int grade;

  do {
    printf("Enter number grade: ");
    scanf("%d", &grade);
  } while (grade < 0 || grade > 100);

  
  p = (grade<50) ? 'F' : 'P';
  

  printf("Result: %c\n", p);
}