#include <stdio.h>
#include <stdlib.h>
size_t ReadHexFile(FILE *inf, unsigned char *dest) {
  size_t count = 0;
  int n;
  if (dest == NULL) {
    unsigned char OneByte;
    while ((n = fscanf(inf, "%hhx", &OneByte)) == 1 ) {
      count++;
    }
  }
  else {
    while ((n = fscanf(inf, "%hhx", dest)) == 1 ) {
      dest++;
    }
  }
  if (n != EOF) {
    ;  // handle syntax error
  }
  return count;
}

int main() {
  FILE *inf = fopen("pawd.txt", "rt");
  size_t n = ReadHexFile(inf, NULL);
  rewind(inf);
  unsigned char *hex = malloc(n);
  ReadHexFile(inf, hex);
  // do somehting with hex
  fclose(inf);
  free(hex);
  return 0;
 }

