#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char **argv) {
  assert(argc == 3 && "usage: ascii_conv $input_fifo $output_fifo");
  openlog("ascii-conv", 0, LOG_USER);

  FILE *in_file = fopen(argv[1], "r");
  if (!in_file) {
    syslog(LOG_ERR, "opening ascii input fifo failed (%m)");
    exit(-1);
  }

  int out_fd = open(argv[2], O_WRONLY);
  if (out_fd == -1) {
    syslog(LOG_ERR, "opening bin output fifo failed (%m)");
    exit(-1);
  }

  syslog(LOG_INFO, "ascii-conv: successfully intialized");
  while (1) {
    int val;
    int ret = fscanf(in_file, "%i", &val);
    if (ret == EOF) {
      if (ferror(in_file) != 0) {
        // not end of file (expected), we would like to know what's goin on
        syslog(LOG_INFO, "ascii integer read error");
      }
      clearerr(in_file);
      continue;
    }
    write(out_fd, &val, sizeof(int));
  }
  close(out_fd);
  fclose(in_file);
}
