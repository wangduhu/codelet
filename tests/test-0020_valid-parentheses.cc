#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "0020_valid-parentheses.c"

TEST_CASE("c solution") {
  CHECK(isValid("()"));
  CHECK(isValid("()[]{}"));
  CHECK(!isValid("(]"));
  CHECK(!isValid("]"));
  CHECK(isValid(""));
  CHECK(!isValid("["));
}

TEST_CASE("c++ solution") {
}
