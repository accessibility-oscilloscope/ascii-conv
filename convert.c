#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

int main(int ac, char *av[])
{
    assert(ac == 3 && "usage: ./convert in-fifo out-fifo");
    int result = 0, val1 = 0, val2 = 0, buffset = 0, offset1 = 0, offset2 = 0;
    char *buffer;
    char arr1[100];
    char arr2[100];

    size_t size = 32;
    u_int8_t output[2];
    bool first = true;

    const char *in_fifo = av[1];
    const char *out_fifo = av[2];

    buffer = (char *)malloc(size * sizeof(char));
    if (buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    const int fd = open(in_fifo, O_RDONLY);
    const int fd_out = open(out_fifo, O_WRONLY);

    while (1)
    {
        result = read(fd, (void *)(&buffer[buffset]), 1);

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

    write(fd_out, &output, 2);
    free(buffer);

    return 0;
}