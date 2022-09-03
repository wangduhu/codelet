#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0020_valid-parentheses.c"
#include "0020_valid-parentheses.cpp"
#include <string>

struct Table {
    string input;
    bool expect;
};

Table table[] = {
    {"()", true},
    {"()[]{}", true},
    {"(]", false},
    {"]", false},
    {"", true},
    {"[", false},
    };

void assertsC() {
    for (auto &row : table) {
      CHECK(isValid(const_cast<char *>(row.input.c_str())) == row.expect);
    }
}

template <typename S> void assertsCpp(S soln) {
    for (auto &row : table) {
        CHECK(soln.isValid(row.input) == row.expect);
    }
}

TEST_CASE("c solutions") { assertsC(); }
TEST_CASE("c solutions") { assertsCpp(Solution()); }
