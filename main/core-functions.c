

char *findGitInDir(char *dir){
  struct dirent *entry;
  DIR *directory = opendir(dir);

  if (dir == NULL){
    return NULL;
  }

  char *res_dir = malloc(MAX_DIR_LEN);

  while ((entry = readdir(directory)) != NULL) {
    if (areStringsEqual(entry->d_name, _APP_DIR)){
      sprintf(res_dir, "%s/%s", dir, _APP_DIR);
      closedir(directory);
      return res_dir;
    }
  }

  closedir(directory);
  free(res_dir);
  return NULL;
}

char *getGitDir(){
  char current_dir[MAX_DIR_LEN];
  
  if (getcwd(current_dir, sizeof(current_dir)) == NULL){
    printf("failed to get current dir!\n");
    exit(1);
  }
  
  while (strlen(current_dir) > 0) {
    char *git_dir = findGitInDir(current_dir);
    if (git_dir != NULL){
      return git_dir;
    }

    char *lastSlash = strrchr(current_dir, '/');

    *lastSlash = '\0';
  }

  return NULL;

}
