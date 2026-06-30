#include "stdio.h"
#include <_inttypes.h>
#include <stdint.h>
#include <stdlib.h>

int find(int *arr, int length) {
  int sum = 0, len = length + 1;
  int sumExp = (len * (len + 1)) / 2;
  while (--length > -1)
    sum += *(arr + length);

  return (sumExp - sum);
}

int main() {
  printf("--- Running Missing Number Test Cases ---\n\n");

  // Testcase 1: Your original unsorted example (Missing 3)
  int tc1[] = {1, 2, 4, 6, 5, 7, 8};
  int size1 = sizeof(tc1) / sizeof(tc1[0]);
  printf("Testcase 1 (Unsorted Middle): Expected 3 -> Got %d\n", find(tc1,
  size1));

  // Testcase 2: Missing the very first number (Missing 1)
  int tc2[] = {5, 3, 2, 4};
  int size2 = sizeof(tc2) / sizeof(tc2[0]);
  printf("Testcase 2 (Missing First/1): Expected 1 -> Got %d\n", find(tc2,
  size2));

  // Testcase 3: Missing the very last number N (Missing 5)
  int tc3[] = {1, 4, 3, 2};
  int size3 = sizeof(tc3) / sizeof(tc3[0]);
  printf("Testcase 3 (Missing Last/N):  Expected 5 -> Got %d\n",
         find(tc3, size3));

  // Testcase 4: Smallest possible array (Missing 1)
  int tc4[] = {2};
  int size4 = sizeof(tc4) / sizeof(tc4[0]);
  printf("Testcase 4 (Single Element):  Expected 1 -> Got %d\n",
         find(tc4, size4));

  // Testcase 5: Smallest possible array (Missing 2)
  int tc5[] = {1};
  int size5 = sizeof(tc5) / sizeof(tc5[0]);
  printf("Testcase 5 (Single Element):  Expected 2 -> Got %d\n",
         find(tc5, size5));

  // Testcase 6: Large sequence highly randomized (Missing 11)
  int tc6[] = {13, 1, 7, 3, 5, 10, 2, 4, 6, 8, 9, 12, 14};
  int size6 = sizeof(tc6) / sizeof(tc6[0]);
  printf("Testcase 6 (Larger Random):   Expected 11 -> Got %d\n",
         find(tc6, size6));

  return 0;
}
