#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "0000_template.cpp"

extern int isValid(char *s);

TEST_CASE("c solution") {
  CHECK(isValid("()"));
  CHECK(isValid("()[]{}"));
  CHECK(!isValid("(]"));
  CHECK(!isValid("]"));
  CHECK(isValid(""));
}

TEST_CASE("c++ solution") {
}
