#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

int val;
char str[20];
strcpy(str, "20000");

val = atoi(str);
printf("%x\n", val);
//printf("Sizeof result is %zu\n", sizeof(int));

return 0;

}