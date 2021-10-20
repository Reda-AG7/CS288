#include<stdio.h>
#include<stdlib.h>

int main(){
unsigned int x;
//****** Method 1 *****
printf("Enter a number : ");
scanf("%ud\n",&x);

int max = 0;
int count = 0;
for(int i=0;i<32;i++){
  unsigned int temp = x & 1;
  //printf("%u\n", temp);
  if(temp == 1) count++;
  else{
    if(count > max) 
      max = count;
    count = 0;
  }
  x >>= 1;
}
if(count > max) 
      max = count;
printf("%d\n", max);
return 0;
/*
***** Method 2 **********
int max = -1;
int count = 0;
while(x/2 > 0){
  if(x%2 == 0){
    if(count > max){
      max = count;
      count=0;
    }
  }
  else count++;
  x/=2;
}
if(x%2 == 1) count++;
if(count > max)
max = count;
printf("%d\n", max);
*/
}