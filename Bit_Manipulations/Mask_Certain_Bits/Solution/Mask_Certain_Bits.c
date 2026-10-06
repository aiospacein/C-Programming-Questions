

int MaskNBits(int a, int Nbits) {
  unsigned int mask = (unsigned int)a & ((1U << (Nbits)) - 1U);
  return mask;
}