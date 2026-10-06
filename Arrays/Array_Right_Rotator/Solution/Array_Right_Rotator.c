#include <stdlib.h>

// Reverse Whole array
// Reverse K elements from left side
// Reverse N-K elements from right side

// for left shift by k is right shift by N-K

void reverse(int *arr, int length) {
  int left = 0;
  int right = length - 1;

  while (left < right) {
    int temp = arr[left];
    arr[left++] = arr[right];
    arr[right--] = temp;
  }
}

void RotateR(int *arr, int length, int RotateBy) {

  if ((length == 0) || (RotateBy == 0))
    return;
  // To this:
  if (arr == NULL || length <= 1)
    return;

  RotateBy = (RotateBy % length + length) %
             length; // adding length to take care on negative values
  reverse(arr, length);

  reverse(arr, RotateBy);
  reverse(arr + RotateBy, length - RotateBy);
}
