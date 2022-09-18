#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0094_binary-tree-inorder-traversal.c"
// #include "0094_binary-tree-inorder-traversal.cpp"

struct Table {
  int input;
  int expect;
};

Table table[] = {
  {}
};

void assertsC() {
  for (auto &row : table) {
    // CHECK(X(row.input) == row.expect);
  }
}

template <typename S> void assertsCpp(S soln) {
  for (auto &row : table) {
    CHECK(soln.X(row.input) == row.expect);
  }
}

TEST_CASE("c solutions") { assertsC(); }
// TEST_CASE("c solutions") { assertsCpp(Solution()); }
