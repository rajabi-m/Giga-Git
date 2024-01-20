#include <string.h>
#define MAX_LINE_LEN 100
struct stat ___st = {0}; // https://stackoverflow.com/questions/7430248/creating-a-new-directory-in-c 

int doesDirExist(char *dir){
  return (stat(dir, &___st) == 0);  
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

void appendToString(char *src, char *str){
  int i;
  for (i = strlen(src);i < strlen(src) + strlen(str);i ++) {
    src[i] = str[i - strlen(src)];
  }
  src[i] = '\0';
}




int copyFile(const char *source_dir, const char *destination_dir){
  
  FILE *source_file = fopen(source_dir, "r");
  if (!source_file){
    return -1; // -1 means source file does not exist.
  }

  FILE *destination_file = fopen(destination_dir, "w");

  char line[MAX_LINE_LEN];
  while (fgets(line, MAX_LINE_LEN, source_file)) {
    if (!fputs(line, destination_file)){
      return -2; // -2 meanes that some error happened while trying to copy file.
    }
  }

  return 1;
}
