



void createSubDirectory(char *dir, char *name){
  char subDir[MAX_DIR_LEN];
  strcpy(subDir, dir);
  strcat(subDir, name);
  mkdir(subDir, 0700); // making data base folder
}


void Git_Initialize(int argc, char **argv){
  char dir[MAX_DIR_LEN];
  sprintf(dir, "./.%s", _APP_NAME);
  if (doesDirExist(dir)) {
    printf("%s directory already exists!\n", _APP_NAME_DISPLAY);
    return;
  } // git directory already exists
  if (mkdir(dir, 0700) == -1){
    printf("error happened while trying to make %s directory :(\n", _APP_NAME_DISPLAY);
    return;
  }

  createSubDirectory(dir, _COMMITS_DIR);
  createSubDirectory(dir, _BRANCHES_DIR);
  createSubDirectory(dir, _CONFIGS_DIR);

  printf("%s directory created :) enjoy using %s\n",dir, _APP_NAME_DISPLAY);


  return;
}
