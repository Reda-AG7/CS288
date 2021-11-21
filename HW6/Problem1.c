#include<stdio.h>
#include<stdlib.h>

void getContentHex(char* argv){
    const unsigned char* ptr = (const unsigned char*)&argv;
    for(int i=7;i>=0;i--)
        printf("%02hhx ",ptr[i]);
}
int main(int argc,char** argv){
    printf("\nargv       | ");
    const unsigned char* ptr = (const unsigned char*)&argv;
    for(int i=7;i>=0;i--)
        printf("%02hhx ",ptr[i]);
    printf(" | %p\n\n",&argv);
    for(int i=0;i<argc;i++){
        printf("argv[%d]    | ",i);
	getContentHex(argv[i]);
        printf(" | %p\n",&argv[i]);
    }
    printf("\n");
    
    ptr = ((const unsigned char*) argv[0]);
    ptr-=7;
    printf("\n");
    for(int j=0;j<=argc;j++){
       printf("           | ");
       for(int i=7;i>=0;i--)
	   printf("%02hhx(%c) ",ptr[i],ptr[i]);
       printf(" | %p\n",&ptr[0]);
       ptr+=8;
    }
    return 0;
}
