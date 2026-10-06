

void UniqueNumbers(int *arr, int length, int *num1, int *num2) {
  int result = 0;
  for (int i = 0; i < length; i++) {
    result ^= arr[i];
  }
  int indx = 0;
  for (int i = 0; i < 32; i++) {
    if (result ^ 0x1) {
      indx = i;
      break;
    }
  }
  int left[]
   for (int i = 0; i < length; i++) {
    result ^= arr[i] 
  }
}

#include <stdio.h>
#include <stdlib.h>

void findTwoUnique(const int* nums, int numsSize, int* out1, int* out2) {
    // Step 1: XOR all elements in the array
    unsigned int xor_all = 0;
    for (int i = 0; i < numsSize; i++) {
        xor_all ^= (unsigned int)nums[i];
    }

    // Step 2: Get the rightmost set bit (diffing bit)
    // Formula: x & -x isolates the lowest 1-bit
    unsigned int diff_bit = xor_all & (-(signed int)xor_all);

    // Step 3: Divide numbers into two groups based on diff_bit and XOR each group
    unsigned int num1 = 0;
    unsigned int num2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if ((unsigned int)nums[i] & diff_bit) {
            num1 ^= (unsigned int)nums[i]; // Group 1: diff_bit is 1
        } else {
            num2 ^= (unsigned int)nums[i]; // Group 2: diff_bit is 0
        }
    }

    *out1 = (int)num1;
    *out2 = (int)num2;
}