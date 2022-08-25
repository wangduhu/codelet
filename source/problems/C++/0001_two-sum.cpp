#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

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

/*
  Status: Accepted (57/57)
  Runtime: 25 ms, faster than 53.77% of C++ submissions.
  Memory Usage: 12.1 MB, less than 12.19% of C++ submissions.
 */
