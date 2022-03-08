#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv)
{

    int result, val1, val2, buffset, offset1, offset2;
    char *buffer;
    char arr1[100];
    char arr2[100];

    size_t size = 32;
    u_int8_t output[2];
    bool first = true;

    buffer = (char *)malloc(size * sizeof(char));
    if (buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
   
    while (1)
    {
        result = read(STDIN_FILENO, (void *) (&buffer[buffset]), 1);
        
        if (result != 1)
        {
            break;
        }
        if (buffer[buffset] == '\n')
        {
            first = false;
        }
        if (first)
        {
            arr1[offset1] = buffer[buffset];
            offset1++;
        }
        else
        {
            arr2[offset2] = buffer[buffset];
            offset2++;
        }
        buffset++;
    }
    

    val1 = atoi(arr1);
    val2 = atoi(arr2);
    output[0] = val1;
    output[1] = val2;

    //printf("%d %d", output[0], output[1]);
    write(STDOUT_FILENO, &output, 2);
    free(buffer);

    return 0;
}