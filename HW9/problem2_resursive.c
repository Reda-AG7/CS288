#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include "sortedList.h"
node* head = NULL;

void traverse(char* path){
  struct stat statBuffer;
  mode_t mode;
  char fileName[1024];
  int result,charsRead;
  DIR* pDir;
  struct dirent* pEnt;
  result = stat(path,&statBuffer);
  if(result == -1){
    fprintf(stderr,"Cannot stat %s \n",path);
    return;
  }
  mode = statBuffer.st_mode;
  if(S_ISREG(mode)){
    addNode(&head,path,statBuffer.st_size);
    return;
  }
  else if(S_ISDIR(mode)){
    pDir = opendir(path);
    while((pEnt = readdir(pDir)) != NULL){
      if(strcmp(pEnt->d_name,".") != 0 && strcmp(pEnt->d_name,"..") != 0){
        sprintf(fileName,"%s/%s",path,pEnt->d_name);
        traverse(fileName);
      }
    }
    closedir(pDir);
  }
}


int main(int argc,char** argv){
  if(argc != 2 || strlen(argv[1]) == 0){
    exit(0);
  }
  traverse(argv[1]);
  displayList(head);
  printf("\nCount = %d\n",count);
  destroyList(&head);
  return 0;
}

