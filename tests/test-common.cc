#include "common.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("main") {
    vector<int> nums({1, 2, 3, 4, 5});
    cout << nums << endl;
    CHECK(vector<int>({1, 2, 3}) == vector<int>({1, 2, 3}));
    CHECK(vector<vector<int>>({{1}, {2}, {3}}) == vector<vector<int>>({{1}, {2}, {3}}));
}
