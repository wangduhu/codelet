

int mySqrt(int x){
  if (x == 0 || x == 1) {
    return x;
  }
  int l = 1;
  int r = x;
  while (l < r) {
    int div = x / r;
    if (div == r) {
      return r;
    } else if (div < r) {
      r = (l + r) / 2;
    } else {
      l = (l + r) / 2;
    }
  }
  return r;
}
