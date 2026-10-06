#include <stdbool.h>
#include <stdlib.h>

bool IsMultipleOf3(int a) {
  int sum = 0;
  int idx = 0;
  while (a > 0) {
    if ((a & 1U) == 1u) {
      if ((idx % 2) == 0) {
        sum++;
      } else
        sum--;
    }
    a = a >> 1;
    idx++;
  }
  if (sum % 3 == 0)
    return true;
  return false;
}