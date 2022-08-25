#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "0000_template.cpp"

extern int factorial(int number);

TEST_CASE("c solution") {
  CHECK(factorial(1) == 1);
  CHECK(factorial(2) == 2);
  CHECK(factorial(3) == 6);
  CHECK(factorial(10) == 3628800);
}

TEST_CASE("c++ solution") {
  Solution soln;
  CHECK(soln.factorial(1) == 1);
  CHECK(soln.factorial(2) == 2);
  CHECK(soln.factorial(3) == 6);
  CHECK(soln.factorial(10) == 3628800);
}
