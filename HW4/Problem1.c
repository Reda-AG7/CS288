#include<stdio.h>
#include<stdlib.h>

int main(){
unsigned int x;
unsigned l,r;

printf("Enter a number : ");
scanf("%ud\n",&x);
printf("starting bit : ");
scanf("%ud\n",&r);
printf("ending bit : ");
scanf("%ud\n",&l);
if(l<r){
	printf("the staring bit is greater the the ending bit");
}
else{
x =	x << (31-l);
x =	x >> (31-(l-r));
printf("%u\n",x);
}

return 0;
}
