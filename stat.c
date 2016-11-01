#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main() {
  struct stat buff;
  stat("stat.c", &buff);
  off_t size = buff.st_size;
  mode_t mode = buff.st_mode;
  char ret[9];
  int i;
  for (i=0; i<9; i++) { ret[i] = '-'; }
  if (mode & S_IRUSR) { ret[0] = 'r'; }
  if (mode & S_IWUSR) { ret[1] = 'w'; }
  if (mode & S_IXUSR) { ret[2] = 'x'; }
  if (mode & S_IRGRP) { ret[3] = 'r'; }
  if (mode & S_IWGRP) { ret[4] = 'w'; }
  if (mode & S_IXGRP) { ret[5] = 'x'; }
  if (mode & S_IROTH) { ret[6] = 'r'; }
  if (mode & S_IWOTH) { ret[7] = 'w'; }
  if (mode & S_IXOTH) { ret[8] = 'x'; }
  time_t timeMod = buff.st_mtime;

  printf("Size: %d bytes\nMode: %s\nTime of last change: %s\n", size, ret, ctime(&timeMod));
  return 0;
}
