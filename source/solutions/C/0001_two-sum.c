#include <stdlib.h>

typedef struct {
  int value;
  int index;
} Object;

static int compare(const void* l, const void* r) {
  return ((Object*)l)->value - ((Object*)r)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  Object* objs = (Object*)malloc(sizeof(Object) * numsSize);
  for (int i = 0; i < numsSize; i++) {
    objs[i].value = nums[i];
    objs[i].index = i;
  }
  qsort(objs, numsSize, sizeof(Object), compare);

  int* ans = (int*)malloc(sizeof(int) * 2);
  *returnSize = 2;
  int i = 0, j = numsSize - 1;
  int sum;
  while (i < j) {
    sum = objs[i].value + objs[j].value;
    if (sum < target) {
      i++;
    } else if (sum > target) {
      j--;
    } else {
      ans[0] = objs[i].index;
      ans[1] = objs[j].index;
      break;
    }
  }

  return ans;
}

/*
  Status: Accepted (57/57)
  Runtime: 17 ms, faster than 92.08% of C submissions.
  Memory Usage: 6.9 MB, less than 8.75% of C submissions.
 */
