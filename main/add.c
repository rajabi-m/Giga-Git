

enum GitAddMode{
  normal = 0,
  muti_mode = 1,
  log_mode = 2,
  redo_mode = 3
};

int stage(const char *path){
  real_path = realpath(path, NULL);
  DIR *directory = opendir(real_path);
  char stage_path[MAX_DIR_LEN];
  if (directory != NULL){
    // it is path to a dir.
    // sprintf(stage_path, "%s%s/%s", global_git_dir - strlen(_APP_NAME) - 2, _STAGE_DIR, real_path + str) TODO
  }
}

int Git_Add(int argc, char **argv){
  if (argc <= 2){
    printf("git add ro boro yad begir seyed\n");
    return -1;
  }
  
  enum GitAddMode mode = normal;

  static struct option long_options[] = {
    {"multi", 0, NULL, 'f'},
    {"log", 0, NULL, 'n'},
    {"redo", 0, NULL, 'r'}
  };
  
  int opt = getopt_long(argc, argv, "fnr", long_options, NULL);
  if (opt != -1){ // if there is any option
    switch (opt) {
      case 'f':{
        mode = multi_mode;
        break;
      }
      case 'n':{
        mode = log_mode;
        break;
      }
      case 'r':{
        mode = redo_mode;
        break;
      }
      default:{
        raiseError();
        return -2;
      }
    }
  }




}
