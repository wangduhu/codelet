#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0206_reverse-linked-list.c"
// #include "0206_reverse-linked-list.cpp"

struct Table {
  vector<int> input;
  vector<int> expect;
};

Table table[] = {
  {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
  {{}, {}},
  {{1}, {1}}
};

void assertsC() {
  for (auto &row : table) {
    struct ListNode *l = make_list(row.input);
    l = reverseList(l);
    CHECK(l == row.expect);
    free_list(l);
  }
}

template <typename S> void assertsCpp(S soln) {
  for (auto &row : table) {
    CHECK(soln.X(row.input) == row.expect);
  }
}

TEST_CASE("c solutions") { assertsC(); }
// TEST_CASE("c solutions") { assertsCpp(Solution()); }
