#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  assert(argc == 1 && "usage: ./reader $INTPUTFIFO");
  int fd = open(argv[1], O_RDONLY);
  int val;
  while (1) {
    int rv = read(fd, &val, sizeof(int));
    printf("rv = %d\n", rv);
    printf("val = %d\n", val);
  }
  return 0;
}
