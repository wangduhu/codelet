#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0086_partition-list.c"
// #include "0086_partition-list.cpp"

struct Table {
  vector<int> nums;
  int x;
  vector<int> expect;
};

Table table[] = {
    {{1, 4, 3, 2, 5, 2}, 3, {1, 2, 2, 4, 3, 5}},
    {{}, 1, {}},
    {{1, 1}, 1, {1, 1}},
    {{6, 5, 4, 3, 2, 1}, 3, {2, 1, 6, 5, 4, 3}},
};

void assertsC() {
  for (auto &row : table) {
    struct ListNode* head = make_list(row.nums);
    struct ListNode* ans = partition(head, row.x);
    CHECK(ans == row.expect);
    free_list(ans);
  }
}

template <typename S> void assertsCpp(S soln) {
  for (auto &row : table) {
    // CHECK(soln.X(row.input) == row.expect);
  }
}

TEST_CASE("c solutions") { assertsC(); }
// TEST_CASE("c solutions") { assertsCpp(Solution()); }
