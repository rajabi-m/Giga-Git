#include <stdbool.h>
#include <getopt.h>
#include <string.h>
  
// https://www.youtube.com/watch?v=rB5I1EKffn0




void loadUserData(){
  char global_conf_file_dir[MAX_DIR_LEN];
  sprintf(global_conf_file_dir, "%s/user.conf", _GLOBAL_CONFIGS_DIR);
  printf("%s\n", global_conf_file_dir);



  FILE *configFile = fopen(global_conf_file_dir, "r");
  if (!configFile){
    if (!doesDirExist(_GLOBAL_CONFIGS_DIR)){
      printf("no global user data dir yet, so i am gonna create one ...\n");
      int out = mkdir(_GLOBAL_CONFIGS_DIR, 0777);
      printf("dir created with error code = %d\n", out);
    }
    
    fopen(global_conf_file_dir, "w");
    configFile = fopen(global_conf_file_dir, "r");
  }


  if (fread(&global_user, sizeof(struct userData), 1, configFile)){
    printf("user loaded succsessfully\n");
  }else {
    printf("no user data on file\n");
    strcpy(global_user.name, " ");
    strcpy(global_user.email, " ");
  }

  fclose(configFile);

  // loading local user data if exists TODO

}

void changeUserData(char *data, char *value, bool is_global){
  is_global = true; // for now
  
  // creating temp copy of userdata and applying changes to it to help us save new data

  struct userData tmp_user = global_user;

  if (areStringsEqual(data, "name")){
    strcpy(tmp_user.name, value);
  }else if (areStringsEqual(data, "email")){
    strcpy(tmp_user.email, value);
  }




  // saving new data
  char dir[MAX_DIR_LEN - 100];
  if (is_global){
    strcpy(dir, _GLOBAL_CONFIGS_DIR);
  }
  
  char conf_file_dir[MAX_DIR_LEN];
  sprintf(conf_file_dir, "%s/user.conf", dir);

  FILE *configFile = fopen(conf_file_dir, "w");
  fwrite(&tmp_user, sizeof(struct userData), 1, configFile);
  fclose(configFile);

  // reload user data
  loadUserData();
}


void Git_Config(int argc, char **argv){
  bool is_global = false;
  static struct option long_options[] = {
    {"global", 1, NULL, 'g'}
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
  sscanf(argv[3], "%[^.].%s", name, value);
  
  char dir[MAX_DIR_LEN];

  if (is_global){
    if (areStringsEqual(name, "user")){
      changeUserData(value, argv[4], true);
    }
  }


}
