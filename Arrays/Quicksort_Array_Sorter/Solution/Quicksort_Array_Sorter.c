#include <stdlib.h>

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int partition(int *arr, int low, int high) {
  int value = arr[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (arr[j] <= value) {
      swap(arr + i, arr + j);
      i++;
    }
  }
  swap(arr + i, arr + high);
  return i;
}

void quickSort(int *arr, int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

void sort(int *arr, int length) {
  if ((arr == NULL) || (length <= 1))
    return;

  int low = 0;
  int high = length - 1;
  quickSort(arr, low, high);
}