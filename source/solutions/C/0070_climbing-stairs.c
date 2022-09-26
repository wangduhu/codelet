

int climbStairs(int n) {
  int prev = 1, cur = 1;
  for (int i = 1; i < n; i++) {
    int tmp = cur;
    cur = cur + prev;
    prev = tmp;
  }
  return cur;
}
