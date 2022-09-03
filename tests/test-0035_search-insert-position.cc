#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0035_search-insert-position.c"
#include "0035_search-insert-position.cpp"
#include <vector>

struct Table {
  vector<int> nums;
  int target;
  int expect;
};

Table table[] = {
    {{1, 3, 5, 6}, 5, 2},
    {{1, 3, 5, 6}, 2, 1},
    {{1, 3, 5, 6}, 7, 4},
    {{1}, 0, 0},
    {{}, 1, 0},
    {{1, 3}, 2, 1}
};

void assertsC() {
  for (auto &row : table) {
      CHECK(searchInsert(row.nums.data(), row.nums.size(), row.target) == row.expect);
  }
}

template <typename S> void assertsCpp(S soln) {
  for (auto &row : table) {
      CHECK(soln.searchInsert(row.nums, row.target) == row.expect);
  }
}

TEST_CASE("c solutions") { assertsC(); }
TEST_CASE("c solutions") { assertsCpp(Solution()); }
