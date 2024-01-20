#include <stdbool.h>
#include <getopt.h>
#include <string.h>
  
// https://www.youtube.com/watch?v=rB5I1EKffn0




void loadUserData(){ // loading user name and user email.
  

  char global_conf_file_dir[MAX_DIR_LEN];
  sprintf(global_conf_file_dir, "%s/user.conf", _GLOBAL_CONFIGS_DIR);
  printf("--global config file = %s\n", global_conf_file_dir);


  // opening global config file.
  FILE *configFile = fopen(global_conf_file_dir, "rb");
  if (!configFile){
    if (!doesDirExist(_GLOBAL_CONFIGS_DIR)){ // creating global config file dir if it does't exist at all
      printf("no global user data dir yet, so i am gonna create one ...\n");
      int out = mkdir(_GLOBAL_CONFIGS_DIR, 0777);
      printf("dir created with error code = %d\n", out);
    }
    
    fopen(global_conf_file_dir, "w"); // creating the global config file
    configFile = fopen(global_conf_file_dir, "rb");
  }


  if (fread(&global_user, sizeof(struct userData), 1, configFile)){
    printf("global user data loaded succsessfully\n");
  }else {
    printf("no user data on global config file\n");
    strcpy(global_user.name, " ");
    strcpy(global_user.email, " ");
  }

  fclose(configFile);

  // loading local user data if exists TODO

  
  sprintf(global_conf_file_dir, "%s%s/user.conf", _CONFGIS_DIR, global_git_dir); // i am sorry for using this :/
  
  
  
  if ((configFile = fopen(global_conf_file_dir, "rb"))){
    fread(&global_user, sizeof(struct userData), 1, configFile);
    printf("loaded local user data\n");
  }
}

void changeUserData(char *data, char *value, bool is_global){
  
  // creating temp copy of userdata and applying changes to it to help us save new data

  // struct userData tmp_user = global_user; there was actually no need for this because program stops working after this command.

  if (areStringsEqual(data, "name")){
    strcpy(global_user.name, value);
  }else if (areStringsEqual(data, "email")){
    strcpy(global_user.email, value);
  }




  // saving new data
  char dir[MAX_DIR_LEN]; // directory to save all data
  if (is_global){
    strcpy(dir, _GLOBAL_CONFIGS_DIR);
  }else {
    char *git_dir = getGitDir();
    if (git_dir == NULL){
      printf("you should be in a %s folder to be able to change user data locally.\n", _APP_NAME);
      exit(1);
    }
    strcpy(dir, git_dir);
    free(git_dir);
  }
  
  char conf_file_dir[MAX_DIR_LEN+20];
  sprintf(conf_file_dir, "%s/user.conf", dir);

  FILE *configFile = fopen(conf_file_dir, "wb");
  fwrite(&global_user, sizeof(struct userData), 1, configFile);
  fclose(configFile);

  // reload user data
  // loadUserData(); // there was actually no need for this because program stops working after this.
}


void Git_Config(int argc, char **argv){
  bool is_global = false;
  static struct option long_options[] = {
    {"global", 0, NULL, 'g'} // adding global option
  };
  
  int opt = getopt_long(argc, argv, "g", long_options, NULL);
  if (opt != -1){
    if (opt == 'g'){
      is_global = true;
    }else {
      raiseError();
      return;
    }
  }

  char name[10];
  char value[20];

  int index = 2;
  if (is_global){
    index ++;
  }

  sscanf(argv[index], "%[^.].%s", name, value);
  
  char dir[MAX_DIR_LEN];

  if (areStringsEqual(name, "user")){
    changeUserData(value, argv[index + 1], is_global);
  }


}
