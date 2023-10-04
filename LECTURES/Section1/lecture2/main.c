#include <stdio.h> //pre processor to enable certain packages
int test() {
    int x = 8;
    int size = 5;
    int i = 0;

    while (i <= size) {
         x = i;
         /*if we did int x = i, we are creating a 
         new variable in our loop block. once we leave the block,
         we will go back to our orginal value
         
         int x = 6
          [int x = 1]
          
          block is now over, so our final value of x will be 6
          
          but if we did
          
          int x = 6
            [x = 1]
            
            our final value of x will be 1. */
        ++i;
    }

    return x;
}
int main() {
    int z = test();
    printf("a \n");
    printf("b \n \n \n \n aa \n");
    printf("%d \n", z);
}


//arity, unary, binary, ternary (how many parameters for an operator)

//precedence (bedmas in which operators rank in priority)
//associtativity which operators are the same



