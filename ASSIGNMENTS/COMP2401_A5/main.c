#include "defs.h"

int main(int argc, char *argv[])
{
  srand( (unsigned)time( NULL ) );
  
  if (argc <= 1) {

    runEscape();
    
  }

  else {
    
    viewEscape(argv[1]);

  }
  
  return 0;
}

int randomInt(int max)
{
  return(rand() % max);
}

