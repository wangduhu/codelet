/*(l, r)左闭右开，返回l
  (N, N + 1)
  N *N <= x
  (N + 1) * (N + 1) > x
*/

int mySqrt(int x) {
  if (x == 0) {
    return 0;
  }
  int l = 1, r = x;
  while (l < r - 1) {
    int m = l + (r - l) / 2;
    if (x / m < m) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}
