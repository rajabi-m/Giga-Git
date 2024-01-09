#include "includes/includes.h"
#include "includes/config.h"
#include "includes/useful-functions.c"
#include "includes/random-stuff.c"
#include "main/init.c"


int main(int argc, char **argv)
{
  if(argc == 1){
    printHelp();
    return 1;
  }
  if(areStringsEqual(argv[1], "init")){
    printf("Trying to Start %s in here ...\n", _APP_NAME_DISPLAY);
    Git_Initialize(argc, argv);
  }
  return 0;
}
