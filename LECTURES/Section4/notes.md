c code -> compilation -> linking

                            vvv
            library code    ^^^ 
                      ->  linking


#include <example.h> used for library code
#include "example.h" used for library code

the linker takes all the object files into an executable

gcc myFile.c will create an object file
<stdio.h> already has an object file

Linking: takes code from multiple object files and mrges into one exe file.

compilation:
    preprocess -> compiler -> assembler
![alt text](di)
