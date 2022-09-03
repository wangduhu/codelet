#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0000_template.c"
#include "0000_template.cpp"

struct Table {
  int num;
  int expect;
};

Table table[] = {{1, 1}, {2, 2}, {3, 6}, {10, 3628800}};

void assertsC() {
  for (auto &row : table) {
    CHECK(factorial(row.num) == row.expect);
  }
}

template <typename S> void assertsCpp(S soln) {
  for (auto &row : table) {
    CHECK(soln.factorial(row.num) == row.expect);
  }
}

TEST_CASE("c solutions") { assertsC(); }
TEST_CASE("c solutions") { assertsCpp(Solution()); }
