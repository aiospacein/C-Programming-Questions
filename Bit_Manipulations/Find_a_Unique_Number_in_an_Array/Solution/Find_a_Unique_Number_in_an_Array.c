

#include "stdlib.h"

int UniqueNo(int *arr, int length) {
  int result = 0;

  while (length--) {
    result ^= arr[length];
  }

  return result;
}

#include <stdio.h>

int findUnique(const int* nums, int numsSize) {
    int ones = 0; // Holds bits that have appeared 1 time (mod 3)
    int twos = 0; // Holds bits that have appeared 2 times (mod 3)

    for (int i = 0; i < numsSize; i++) {
        // Add current number to 'ones' only if it's not already in 'twos'
        ones = (ones ^ nums[i]) & ~twos;

        // Add current number to 'twos' only if it's not already in 'ones'
        twos = (twos ^ nums[i]) & ~ones;
    }

    return ones;
}