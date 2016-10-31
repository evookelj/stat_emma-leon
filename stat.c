#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main() {
  struct stat buff;
  stat("stat.c", &buff);
  off_t size = buff.st_size;
  mode_t mode = buff.st_mode;
  time_t timeMod = buff.st_mtime;
  int statchmod = mode & (S_IRWXU | S_IRWXG | S_IRWXO);
  
  printf("Size: %d bytes\nMode (last 3 digits = owner/group/others): %o\nTime of last change: %s\n", size, statchmod, ctime(&timeMod));
  return 0;
}
