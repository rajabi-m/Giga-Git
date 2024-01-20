#include <stdio.h>
#define MAX_LINE_LEN 5


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


int main(int argc, char *argv[])
{
  if (copyFile("../README.md", "../new.txt") != 1){
    printf("vaaaaaaaaay");
  }
  return 0;
}

