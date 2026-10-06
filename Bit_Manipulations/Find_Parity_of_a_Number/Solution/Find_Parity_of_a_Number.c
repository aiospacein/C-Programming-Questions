
#include "stdlib.h"

char *parity(int a) {
  int sum = 0;
  while (a) {
    if (a & (a - 1))
      sum++;
    a >>= 1;
  }
  if (sum % 2) {
    return "even";
  }
  return "odd";
}


char* parity(int a) {
    unsigned int x = (unsigned int)a;
    int sum = 0;

    // Clears the lowest set bit in each iteration
    while (x > 0) {
        x &= (x - 1U);
        sum++;
    }

    return (sum % 2 != 0) ? "Odd" : "Even";
}