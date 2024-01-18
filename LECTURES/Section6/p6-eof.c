#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 32

int main()
{
  FILE *infile;  
  char  name[MAX_STR];
  char  major[MAX_STR];
  float gpa;
  
  infile = fopen("students.txt", "r");
  if (!infile) {
    printf("Could not open file.\n");
    exit(1);
  }


  while (1) {

    if (feof(infile)) {
      break;
    }

    fscanf(infile, "%s %s %f", name, major, &gpa);
    printf("student name: %s; Major: %s; GPA: %4.1f\n", name, major, gpa);

  
  }

  fclose(infile);
}
