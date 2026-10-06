// make array of it modulus
// sort that array
// count the sum of pairs whos sum is K and pair of zeros

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool NoOfPairs(const int *arr, int length, int k) {
  if ((arr == NULL) || (length <= 1) || (k <= 0)) {
    return false;
  }

  int *modArr = malloc(sizeof(*modArr) * length);
  if (!modArr)
    return false;

  for (int i = 0; i < length; i++) {
    modArr[i] = ((arr[i] % k) + k) % k;
  }

  sort(modArr, length);

  int idx = 0, zeroCount = 0, right = length - 1;
  while ((idx <= right) && (modArr[idx] == 0)) {
    zeroCount++;
    idx++;
  }
  if (zeroCount % 2 != 0) {
    free(modArr);
    return false;
  }
  int pairCout = 0;
  int halfModCount = 0;
  while (idx < right) {
    if (modArr[idx] == k / 2) {
      while ((idx <= right) && (modArr[idx++] == k / 2)) {
        halfModCount++;
      }
      if (halfModCount % 2 != 0) {
        free(modArr);
        return false;
      }
      continue;
    }
    if ((modArr[idx] + modArr[right]) == k) {
      pairCout++;
      idx++;
      right--;
    } else {
      free(modArr);
      return false;
    }
  }
  if (pairCout % 2 != 0) {
    free(modArr);
    return false;
  }
  free(modArr);
  return true;
}