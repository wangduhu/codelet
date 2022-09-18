#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0141_linked-list-cycle.c"
// #include "0141_linked-list-cycle.cpp"

struct Table {
  vector<int> input;
  bool expect;
};

Table table[] = {
  {{}, false}
};

void assertsC() {
  for (auto &row : table) {
    ListNode *l = make_list(row.input);
    CHECK(hasCycle(l) == row.expect);
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
