#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0021_merge-two-sorted-lists.c"
#include "0021_merge-two-sorted-lists.cpp"

#include <vector>

struct Table {
  vector<int> nums1;
  vector<int> nums2;
  vector<int> expect;
};

Table table[] = {
    {{1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}},
    {{}, {}, {}}
};

void assertsC() {
  for (auto &row : table) {
    ListNode *l1 = make_list(row.nums1);
    ListNode *l2 = make_list(row.nums2);
    ListNode *l = mergeTwoLists(l1, l2);
    CHECK(l == row.expect);
    free_list(l);
  }
}

template <typename S> void assertsCpp(S soln) {
  for (auto &row : table) {
    ListNode *l1 = make_list(row.nums1);
    ListNode *l2 = make_list(row.nums2);
    ListNode *l = soln.mergeTwoLists(l1, l2);
    CHECK(l == row.expect);
    free_list(l);
  }
}

TEST_CASE("c solutions") { assertsC(); }
TEST_CASE("c solutions") { assertsCpp(Solution()); }
