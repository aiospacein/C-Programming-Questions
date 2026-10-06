#include <stdbool.h>
#include <stdlib.h>

bool IsPwrOf2(int a) { return (a > 0) && ((a & (a - 1)) == 0); }
