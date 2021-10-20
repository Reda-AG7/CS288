#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void convertChar(char*);

int main() {
	char string[127];
	printf("Enter a string : ");
	scanf("%[^\n]", string);
	if (strlen(string) > 127)
		printf("size exceeded");
	else {
		for (int i = 0; i < strlen(string); i++)
			convertChar(&string[i]);
		printf("%s\n", string);
	}
	return 0;
}

void convertChar(char* c) {
	char cNot = ~(*c);
	*c &= 0xf0;
	cNot &= 0x0f;
	*c |= cNot;
}