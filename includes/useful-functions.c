#include <string.h>

struct stat st = {0}; // https://stackoverflow.com/questions/7430248/creating-a-new-directory-in-c 

int doesDirExist(char *dir){
  return (stat(dir, &st) == 0);  
}

int areStringsEqual(const char *str1, const char *str2){
  return strcmp(str1, str2) == 0;
}

void raiseError(){
  printf("What The Hell? \n");
}

void printHelp(){
  printf("dadash badan behet yad midam\n");
}


