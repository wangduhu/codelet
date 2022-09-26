

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
  int i;
  for (i = digitsSize - 1; i >= 0; i--) {
    if (digits[i] < 9) {
      digits[i] += 1;
      break;
    } else {
      digits[i] = 0;
    }
  }

  int *ans = NULL;
  if (i >= 0) {
    ans = (int *)malloc(sizeof(int) * digitsSize);
    memcpy(ans, digits, sizeof(int) * digitsSize);
    *returnSize = digitsSize;
  } else {
    ans = (int *)malloc(sizeof(int) * (digitsSize + 1));
    memcpy(ans + 1, digits, sizeof(int) * digitsSize);
    ans[0] = 1;
    *returnSize = digitsSize + 1;
  }
  return ans;
}
