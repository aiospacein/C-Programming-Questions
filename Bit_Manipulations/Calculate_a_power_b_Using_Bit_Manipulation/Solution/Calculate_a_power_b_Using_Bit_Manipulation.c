/*Write a function to calculate  a^b Using Bit Manipulation :

WTD: Given two integers a and b, calculate a^b using bitwise operations. Avoid
using the power operator or any other arithmetic operations.

(e.g.: I/P: 2, 3; O/P: 8)*/

#include <stdio.h>

long long power(int base, int power) {
  long long result = 1UL;

  while (power > 0) {
    if (power & 0x1) {
      result *= base;
    }
    base *= base;
    power = power >> 1;
  }

  return result;
}

int main() {
  int a, b, result = 1;

  printf("%d", result);

  return 0;
}