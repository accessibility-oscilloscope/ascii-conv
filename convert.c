#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {

int i=1,j,tmp, val,remainder,quotient;
char hexadecimalNumber[100];

char *buffer;
size_t size = 32;
char* str;

buffer = (char *)malloc(size * sizeof(char));
if( buffer == NULL)
{
    perror("Unable to allocate buffer");
    exit(1);
}

printf("Type a number to convert: ");
getline(&buffer,&size,stdin);

val = atoi(buffer);

quotient = val;

while(quotient!=0) {
	tmp = quotient % 16;
	//To convert integer into character
	if( tmp < 10)
		        tmp =tmp + 48; else
		        tmp = tmp + 55;
	hexadecimalNumber[i++]= tmp;
	quotient = quotient / 16;
	}

	for (j = i -1 ;j> 0;j--)
	      printf("%c",hexadecimalNumber[j]);

//printf("%x\n", val);
//printf("Sizeof result is %zu\n", sizeof(int));

return 0;

}