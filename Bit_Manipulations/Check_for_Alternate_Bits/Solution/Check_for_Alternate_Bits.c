/* Check for Alternate Bits. Write a function to check if bits in a given number
are in alternate pattern.

WTD: Given an integer, check if the bits in its binary representation alternate
between 0 and 1. Use bitwise operations to traverse the bits and perform the
check.

(e.g.: I/P:  0b10101010; O/P: True) */

#include <stdbool.h>
#include <stdio.h>

bool checkAltBits(int a) {
  unsigned int x = (unsigned int)a ^ ((unsigned int)a >> 1U);
  return ((x & (x + 1)) == 0);
}

int main() {
  int a;
  scanf("%u", &a); // inputting unsigned integer

  if (checkAltBits(a))
    printf("True");
  else
    printf("False");

  return 0;
}