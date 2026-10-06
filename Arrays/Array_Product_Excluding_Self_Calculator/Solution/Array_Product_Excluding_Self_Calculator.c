/* Compute the product of an array except self.

WTD: For every index in the array, calculate the product of all numbers except
for the number at that index.

(e.g.: I/P: [1,2,3,4], O/P: [24,12,8,6])*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void arrProd(int *arr, int length) {
  long long product = 1;
  for (size_t i = 0; i < length; i++) {
    if (arr[i] != 0) {
      product *= arr[i];
    }
  }
  for (size_t i = 0; i < length; i++) {
    if (arr[i] != 0) {
      arr[i] /= product;
    }
  }
}

int *arrayProd(int *arr, int length) {

  int *res = malloc(sizeof(*res) * length);

  if (!res) {
    return NULL;
  }
  res[0] = 1;

  for (size_t i = 1; i < length; i++) {
    res[i] = res[i - 1] * arr[i - 1];
  }
  int prod = 1;
  for (size_t i = length - 1; i >= 0; i--) {
    res[i] *= prod;
    prod *= arr[i];
  }

  return res;
}