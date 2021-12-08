#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

FILE* fileObjectT = NULL,*fileObjectB = NULL;
const char* textFileName = "numbers.txt";
const char* binFileName = "numbers.bin";

int getData(FILE* filePtr,int index){
  int count = 0;
  int save = -1;
  fseek(fileObjectT,0,SEEK_SET);
  while(count < index){
    fscanf(filePtr,"%d",&save);
    count++; 
  }
  return save;
}
int nbRecord(FILE* stream){
  int n = 0;
  fseek(stream,0,SEEK_END);
  n = ftell(stream)/sizeof(int);
  return n;
}
int main(){
	fileObjectT = fopen(textFileName,"r");
	fileObjectB = fopen(binFileName,"rb");
	if(fileObjectT == NULL || fileObjectB == NULL)
		printf("one or both the files is not opened successfully\n");
	else{
		int x = 0;
    int nbRec = nbRecord(fileObjectB);
    printf("nb records : %d\n",nbRec);
		while(true){
			printf("input index : ");
			if(scanf("%d",&x) == EOF) break;
			else{
        if(x > nbRec) printf("don't have this record number\n");
        else{
          int myData = 0;
          //reading from text file
          myData = getData(fileObjectT,x);
          printf("Integer saved in text file : %d\n",myData);
          //reading from Binary file
          fseek(fileObjectB,(x-1)*sizeof(int),SEEK_SET);
				  fread(&myData,sizeof(int),1,fileObjectB);
          printf("Integer saved in binary file : %d\n",myData);
        }
			}
		}
		fclose(fileObjectT);
		fclose(fileObjectB);
	}
	
	return 0;

}
