#include <stdlib.h>

char *DecToBin(int a) {
  char *res = malloc(sizeof(a) * 8);
  if (!res) {
    return NULL;
  }
  int msbIdx = a^(a<<1);
  char *start = res;
  while (a > 0) {
    if (a & 0x1u)
      *res++ = '1';
    else
      *res++ = '0';
    a = a >> 1;
  }
  return start;
}