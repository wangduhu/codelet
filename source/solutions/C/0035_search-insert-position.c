

int searchInsert(int* nums, int numsSize, int target) {
  int l = 0;
  int r = numsSize;
  int m;
  while (l < r) {
    m = (l + r) / 2;
    if (nums[m] == target) {
        return m;
    } else if (nums[m] < target) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}

/*
  Status: Accepted (64/64)
  Runtime: 12 ms, faster than 12.91% of C submissions.
  Memory Usage: 6.2 MB, less than 10.05% of C submissions.
 */
