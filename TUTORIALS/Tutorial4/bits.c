#include <stdio.h>

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
void printBits(unsigned char);

int main() {

  unsigned char a = 'A';
  unsigned char arr[2][3][4] = {
                                  {
                                    {62,138,241,129},
                                    {8,221,163,159},
                                    {91,158,169,150}
                                 },
                                  {
                                    {15,138,251,198},
                                    {14,211,161,158},
                                    {77,204,188,217}
                                  }
                                };

  

  printBits(a);
  a = setBit(a, 2);
  a = setBit(a, 3);
  printBits(a);
  a = clearBit(a, 2);
  printBits(a);
  printf("\n");

  /* implement question 4 here */
  //a
  for (int i = 0; i < 2; i ++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        unsigned char selected = arr[i][j][k];
        unsigned char selected_clear = clearBit(selected, 6);
        arr[i][j][k] = selected_clear;
      }
    }
  }
  //b
  for (int i = 0; i < 2; i ++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        unsigned char selected = arr[i][j][k];
        unsigned char selected_clear = setBit(selected, 3);
        arr[i][j][k] = selected_clear;
      }
    }
  }
  //c
  for (int i = 0; i < 2; i ++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 4; k++) {
        unsigned char selected = arr[i][j][k];
        printf("%d ", selected);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}


unsigned char getBit(unsigned char c, int n) {
  return ((c & (1 << n)) >> n);
  }

unsigned char setBit(unsigned char c, int n) {
  return c | (1 << n);
}

unsigned char clearBit(unsigned char c, int n) {
  return (c & (~(1 << n)));
}

void printBits(unsigned char c) {
  for (int i = 7; i >= 0; i--) {
    if (i == 3) {printf(" ");}
    printf("%u" , getBit(c,i));
    
  }
  printf("\n");
}

