#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

FILE* fileObjectT = NULL,*fileObjectB = NULL;
const char* textFileName = "numbers.txt";
const char* binFileName = "numbers.bin";

int main(){
	fileObjectT = fopen(textFileName,"w");
	fileObjectB = fopen(binFileName,"wb");
	if(fileObjectT == NULL || fileObjectB == NULL)
		printf("one or both the files is not opened successfully\n");
	else{
		int x = 0;
		int index = 1;
		while(true){
      /*for(int i=0;i<200;i++){
        fprintf(fileObjectT,"%d\n",i*2);
        int l = 2*i;
        fwrite(&l,4,1,fileObjectB);
      }*/
			printf("input data %d :",index++);
			if(scanf("%d",&x) == EOF) break;
			else{
				fprintf(fileObjectT,"%d\n",x);
				fwrite(&x,sizeof(int),1,fileObjectB);
			}
		}
		fclose(fileObjectT);
		fclose(fileObjectB);
	}
	
	return 0;

}
