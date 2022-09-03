#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <vector>
using namespace std;

#include "0035_search-insert-position.cpp"
#include "0035_search-insert-position.c"

extern int searchInsert(int *nums, int numsSize, int target);

TEST_CASE("c solution") {
  {
    int nums[] = {1, 3, 5, 6};
    CHECK(searchInsert(nums, 4, 5) == 2);
  }
  {
    int nums[] = {1, 3, 5, 6};
    CHECK(searchInsert(nums, 4, 2) == 1);
  }
  {
    int nums[] = {1, 3, 5, 6};
    CHECK(searchInsert(nums, 4, 7) == 4);
  }
  {
    int nums[] = {1};
    CHECK(searchInsert(nums, 1, 0) == 0);
  }
  {
    int nums[] = {};
    CHECK(searchInsert(nums, 0, 1) == 0);
  }
  {
    int nums[] = {1, 3};
    CHECK(searchInsert(nums, 2, 2) == 1);
  }
}

TEST_CASE("c++ solution") {
  Solution soln;
  {
    vector<int> nums({1, 3, 5, 6});
    CHECK(soln.searchInsert(nums, 5) == 2);
  }
  {
    vector<int> nums({1, 3, 5, 6});
    CHECK(soln.searchInsert(nums, 2) == 1);
  }
  {
    vector<int> nums({1, 3, 5, 6});
    CHECK(soln.searchInsert(nums, 7) == 4);
  }
  {
      vector<int> nums({1});
    CHECK(soln.searchInsert(nums, 0) == 0);
  }
  {
    vector<int> nums;
    CHECK(soln.searchInsert(nums, 1) == 0);
  }
  {
    vector<int> nums({1, 3});
    CHECK(soln.searchInsert(nums, 2) == 1);
  }
}
