#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char string[127];
  int count = 0;
	printf("Enter a string : ");
	scanf("%[^\n]", string);
	if (strlen(string) > 127)
		printf("size exceeded");
	else {
    for(int i=0;i<strlen(string);i++){
      char byte = string[i];
      for(int j=0;j<8;j++){
        unsigned int temp = byte & 1;
        if(temp == 0)
          count++;
        byte>>=1;
      }
    }
  }
  printf("number of zeros : %d\n",count);
	return 0;
}

