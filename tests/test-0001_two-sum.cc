#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include <cstdlib>
#include <vector>

#include "0001_two-sum.c"
#include "0001_two-sum.cpp"

struct Table {
  vector<int> nums;
  int target;
  vector<int> expect;
};

Table table[] = {{{2, 7, 11, 15}, 9, {0, 1}}};

void assertsC() {
  for (auto &row : table) {
    int len;
    int *ans = twoSum(row.nums.data(), row.nums.size(), row.target, &len);
    vector<int> tmp(ans, ans + len);
    CHECK(tmp == row.expect);
    free(ans);
  }
}

template <typename S> void assertsCpp(S soln) {
  for (auto &row : table) {
      CHECK(soln.twoSum(row.nums, row.target) == row.expect);
  }
}

TEST_CASE("c solutions") { assertsC(); }
TEST_CASE("c solutions") { assertsCpp(Solution()); }
