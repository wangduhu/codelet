#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

/*
  Status: Accepted (64/64)
  Runtime: 16 ms, faster than 6.22% of C++ submissions.
  Memory Usage: 9.8 MB, less than 23.01% of C++ submissions.
 */
