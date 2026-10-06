#include <stdlib.h>

int ClrBitsFromMsbToIdx(int a, int idx) {
  int mask = (1 << idx);
  return (a & (mask - 1));
}