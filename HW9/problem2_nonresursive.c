#include<stdio.h>
#include<stdlib.h>
#include "sortedList.h"
#include "stackList.h"
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<stdbool.h>

node* head =NULL;
stackNode* headStk = NULL,*tail = NULL;

void traverse(char* dirName){
  addNodeStk(&headStk, &tail, dirName);
  //displayAllDir(headStk);
  while(headStk != NULL){
    DIR* pDir = opendir(headStk->pathDir);
    struct dirent* pEnt;
    while(true){
      pEnt = readdir(pDir);
      char fileName[1024];
      if(pEnt == NULL) break;
      if(strcmp(pEnt->d_name, ".") !=0 && strcmp(pEnt->d_name, "..")!= 0){
        sprintf(fileName,"%s/%s",headStk->pathDir,pEnt->d_name);
        struct stat statBuffer;
        int result = stat(fileName,&statBuffer);
        mode_t mode = statBuffer.st_mode;
        if(result == -1){
          fprintf( stderr, "Cannot stat %s \n", fileName );
          continue;
        }
        else{
          if(S_ISDIR(mode))
            addNodeStk(&headStk, &tail, fileName);
          else if(S_ISREG(mode))
            addNode(&head, fileName, statBuffer.st_size);
        }
      } 
    }
    pop(&headStk);
  }
}

int main(int argc, char** argv){
  if(argc != 2 || strlen(argv[1]) == 0){
    exit(1);
  }
  traverse(argv[1]);
  displayList(head);
  destroyList(&head);

  return 0;
}