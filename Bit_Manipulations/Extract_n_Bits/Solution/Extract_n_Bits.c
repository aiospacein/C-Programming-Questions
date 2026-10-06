#include <stdlib.h>

int ExtractNbitFromIdx(int val, int n, int bitpos) {
  int mask = ((1 << n) - 1U) << bitpos;
  return (val & mask) >> bitpos;
}


#include <stdint.h>

uint32_t ExtractNbitFromIdx(uint32_t val, int n, int bitpos) {
    if (n <= 0 || bitpos < 0 || bitpos + n > 32) {
        // handle error however fits your codebase
        return 0;
    }
    uint32_t mask = (n == 32) ? 0xFFFFFFFFu : ((1u << n) - 1u);
    return (val >> bitpos) & mask;
}