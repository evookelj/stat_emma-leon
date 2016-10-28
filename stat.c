#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  struct stat buff;
  stat("stat.c", &buff);
  int size = buff.st_size;
  int mode = buff.st_mode;
  int timeMod = buff.st_mtime;
  printf("Size: %d\nMode: %d\nTime of last change: %d\n", size, mode, timeMod);
  return 0;
}
