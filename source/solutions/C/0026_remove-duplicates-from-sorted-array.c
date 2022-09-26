

int removeDuplicates(int* nums, int numsSize){
  int i = 0, j = 1;
  do {
    while ((j < numsSize) && (nums[j] == nums[i])) {
      j++;
    }
    if (j >= numsSize) {
      break;
    }
    nums[++i] = nums[j];
  } while (true);
  return i+1;
}
