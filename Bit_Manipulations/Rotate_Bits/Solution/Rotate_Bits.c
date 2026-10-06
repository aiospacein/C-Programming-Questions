

int RotateBitsToLeft(int s, int RotateBy) {
  if ((s == 0) || (RotateBy == 0))
    return 0;
  unsigned int res = (unsigned int)(s << RotateBy);
  unsigned int UpperSide = (unsigned int)(s) & ~((1U << RotateBy) - 1);
  return (res | (UpperSide >> RotateBy));
}