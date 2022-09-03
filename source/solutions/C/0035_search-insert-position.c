int searchInsert(int* nums, int numsSize, int target) {
  int l = 0;
  int r = numsSize;
  int m;
  while (l < r) {
    m = l +  (r - l) / 2;
    if (nums[m] < target) {
        l = m + 1;
    } else {
        r = m;
    }
  }
  return l;
}
