#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <unistd.h>

int
main(int argc, char** argv)
{
  mkfifo("/tmp/testingfifo", 0666);
  FILE* in_file = fopen("/tmp/testingfifo", "r");
  while (1)
  {
    int val;
    int ret = fscanf(in_file, "%i", &val);
    if (ret == EOF)
    {
      if (ferror(in_file) != 0)
      {
        // not end of file (expected), we would like to know what's goin on
        syslog(LOG_ERR, "error %i\n", ferror(in_file));
      }
      clearerr(in_file);
      continue;
    }
    write(STDOUT_FILENO, &val, sizeof(int));
  }
}
