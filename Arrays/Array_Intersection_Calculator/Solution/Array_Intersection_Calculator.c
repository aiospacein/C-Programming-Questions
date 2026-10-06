#include <stddef.h>
#include <stdlib.h>
// #include <stdint.h>

int *ArrInterSecCal(const int *array1, size_t sz1, const int *array2,
                    size_t sz2, size_t *ret_size) {
  size_t size = sz1 > sz2 ? sz1 : sz2;

  if (!ret_size) {
    return 0;
  }

  if (!size) {
    *ret_size = 0;
    return 0;
  }

  int *buff = malloc(sizeof(int) * size);
  size_t buffIdx = 0;
  if (!buff)
    return NULL;

  for (size_t i = 0; i < sz1; i++) {
    for (size_t j = 0; j < sz2; j++) {
      if (array1[i] == array2[j]) {
        size_t k = 0;
        for (; k < buffIdx; k++) {
          if (buff[k] == array1[i]) {
            break;
          }
        }
        if (k == buffIdx) {
          buff[buffIdx++] = array1[i];
          break;
        }
      }
    }
  }

  *ret_size = buffIdx;
  return buff;
}
