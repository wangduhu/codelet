#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "0001_two-sum.c"

TEST_CASE("testing the factorial function") {
  {
    int nums[] = { 2,7,11,15 };
    int tmp;
    int* ans = twoSum(nums, 4, 9, &tmp);
    CHECK(ans[0] == 0);
    CHECK(ans[1] == 1);
  }
}
