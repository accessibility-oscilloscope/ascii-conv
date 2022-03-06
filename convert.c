#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 
#include <unistd.h>

int main(int argc, char** argv) {

int i=1,j,tmp, val,remainder,quotient,fd;
char hexadecimalNumber[100];

char *buffer;
size_t size = 32;

buffer = (char *)malloc(size * sizeof(char));
if( buffer == NULL)
{
    perror("Unable to allocate buffer");
    exit(1);
}

//printf("Type a number to convert: ");
//getline(&buffer,&size,stdin);

fd = open("test.txt", O_RDONLY);
read(fd, buffer, size);

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

free(buffer);
return 0;

}