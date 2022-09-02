

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

/*
  Status: Accepted (64/64)
  Runtime: 6 ms, faster than 63.03% of C submissions.
  Memory Usage: 5.9 MB, less than 99.43% of C submissions.
 */
