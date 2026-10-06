
int IsolateRightMostSetBit(int a) {
  int res = a & (((a - 1)<<1)|0x1);

}