

#include <stdbool.h>
#include <stdlib.h>

bool bitPalindrom(int a) {
  // reverse a
  unsigned int x = a;
  int leftIdx = 0, rightIdx = 0;

  while ((x >> (rightIdx + 1)) > 0) {
    rightIdx++;
  }

  while (leftIdx < rightIdx) {
    int leftBit = (a & (1U << leftIdx)) != 0;
    int rightBit = (a & (1U << rightIdx)) != 0;

    if (leftBit != rightBit) {
      return false;
    }
    leftIdx++;
    rightIdx--;
  }
  return true;
}