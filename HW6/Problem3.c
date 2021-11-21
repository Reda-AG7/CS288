#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void bubbleSort(char** envp,const int size){
    for(int pass = 0;pass<5;pass++){
        bool flag = false;
        for(int i=0;i<5-pass-1;i++){
            char name1[strlen(envp[i])];strcpy(name1,envp[i]);
	    char name2[strlen(envp[i+1])];strcpy(name2,envp[i+1]);
	    char* temp1 = strtok(name1,"=");
            char* temp2 = strtok(name2,"=");
            if(strcmp(temp1,temp2) > 0){
                char* ptr = envp[i];
                envp[i] = envp[i+1];
                envp[i+1]=ptr;
                flag = true;
            } 
        }
        if(!flag) break;
    }
  for(int i=0;i<size;i++)
    printf("%s\n",envp[i]);
}
int main(int argc,char** argv,char** envp){
    int index = 0;
    while(envp[index])
        index++;
    bubbleSort(envp,index);
    return 0;
}
