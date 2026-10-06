/* Compute the leaders in an array.

WTD: Traverse the array from right to left, finding numbers that remain the
largest compared to all numbers on their right.

(e.g.: I/P: [16,17,4,3,5,2], O/P: [17,5,2]) */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int *find_leaders(const int arr[], size_t length, size_t *ResLen) {

  if (!ResLen) {
    return NULL;
  }

  if (!length) {
    *ResLen = 0;
    return NULL;
  }

  int *res = malloc(sizeof(int) * length);
  if (!res) {
    *ResLen = 0;
    return NULL;
  }

  size_t count = 0;
  size_t i = length - 1;

  int lastMax = arr[i];
  res[count++] = lastMax;

  while (i > 0) {
    --i;

    if (arr[i] > lastMax) {
      lastMax = arr[i];
      res[count++] = lastMax;
    }
  }
  //   int lastMax = arr[--length];
  //   size_t count = 0;
  //   res[count++] = lastMax;

  //   do {
  //     --length;
  //     if (arr[length] > lastMax) {
  //       lastMax = arr[length];
  //       res[count++] = lastMax;
  //     }
  //   } while (length != 0);

  int *tmp = realloc(res, count * sizeof(*res));

  if (!tmp) {
    free(res);
    *ResLen = 0;
    return NULL;
  }

  res = tmp;

  *ResLen = count;
  size_t left = 0;
  size_t right = --count;
  while (left < right) {
    int temp = res[left];
    res[left++] = res[right];
    res[right--] = temp;
  }

  return res;
}