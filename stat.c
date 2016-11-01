#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

char* convertSet(int num) {
  if (num == 7) { return "rwx"; }
  if (num == 6) { return "rw-"; }
  if (num == 5) { return "r-x"; }
  if (num == 4) { return "r--"; }
  if (num == 3) { return "-wx"; }
  if (num == 2) { return "-w-"; }
  if (num == 1) { return "--x"; }
  return "---";
}

char numToLs(int octal) {
  char * ret[9];
  printf("%s\n", convertSet(octal / 100) );
  printf("ret %s\n" , ret);
  strcat(ret, convertSet(octal / 100));
  printf("ret: %s\n",ret);
}

int main() {
  struct stat buff;
  stat("stat.c", &buff);
  off_t size = buff.st_size;
  mode_t mode = buff.st_mode;
  time_t timeMod = buff.st_mtime;
  int statchmod = mode & (S_IRWXU | S_IRWXG | S_IRWXO);
  numToLs(statchmod);
  
  printf("Size: %d bytes\nMode (last 3 digits = owner/group/others): %o\nTime of last change: %s\n", size, statchmod, ctime(&timeMod));
  return 0;
}
