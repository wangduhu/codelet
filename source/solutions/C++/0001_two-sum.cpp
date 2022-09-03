#include <vector>

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> visited;
    int current, expected;
    vector<int> result;
    for (size_t i = 0; i < nums.size(); ++i) {
      current = nums[i];
      expected = target - current;
      if (visited.find(expected) != visited.end()) {
        result.push_back(visited[expected]);
        result.push_back(i);
      } else {
        visited[current] = i;
      }
    }
    return result;
  }
};
