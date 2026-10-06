#include <stdlib.h>

int CntNoFlips(int a, int b) {
  int count = 0, res = a ^ b;
  while (res > 0) {

    //or use brian karneghans algo res &= (res -1); clearing right most set bit
    if ((res & 0x1u) == 1)
      count++;
    res = res >> 1;
  }
  return count;
}