#include "globals.c"
#include "includes/includes.h"
#include "includes/config.h"
#include "includes/useful-functions.c"
#include "includes/random-stuff.c"
#include "main/init.c"
#include "main/config.c"




int main(int argc, char **argv)
{

  loadUserData();

  if(argc == 1){
    printHelp();
    return 1;
  }
  if(areStringsEqual(argv[1], "init")){
    printf("Trying to Start %s in here ...\n", _APP_NAME_DISPLAY);
    Git_Initialize(argc, argv);
  } else if (areStringsEqual(argv[1], "config")) {
    Git_Config(argc, argv);
  }

  return 0;
}
