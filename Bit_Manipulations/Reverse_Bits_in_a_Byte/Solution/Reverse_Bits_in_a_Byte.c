char ReverseBitsInBytes(char val) {
  val ^= 0x55;
  val ^= 0x33;
  val ^= 0x0F;
  return val;
}