#include <type_traits>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0507_perfect-number.c"
#include "0507_perfect-number.cpp"

struct Table {
  int input;
  bool expect;
};

Table table[] = {
    {28, true},
    {7, false},
    {1, false},
};

void assertsC() {
  for (auto &row : table) {
    CHECK(checkPerfectNumber(row.input) == row.expect);
  }
}

template <typename S> void assertsCpp(S soln) {
  for (auto &row : table) {
    CHECK(soln.checkPerfectNumber(row.input) == row.expect);
  }
}

TEST_CASE("c solutions") { assertsC(); }
TEST_CASE("c solutions") { assertsCpp(Solution()); }
