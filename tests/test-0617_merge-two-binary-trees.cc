#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "intf.h"

using namespace std;

#include "0617_merge-two-binary-trees.c"
#include "0617_merge-two-binary-trees.cpp"
#include <vector>
#include <iostream>

struct Table {
  vector<string> root1;
  vector<string> root2;
  vector<int> expected;
};

Table table[] = {
    {{"1", "3", "2", "5"},
     {"2", "1", "3", "#", "4", "#", "7"},
     {3, 4, 5, 4, 5, 7}},
};

void assertsC() {
  for (auto &row : table) {
    TreeNode *root1 = construct_binary_tree(row.root1);
    TreeNode *root2 = construct_binary_tree(row.root2);
    TreeNode *root = mergeTrees(root1, root2);
    cout << "CHECK: " << row.root1 << endl;
    cout << root << endl;
    CHECK(root == row.expected);
    free_tree(root);
  }
}

template <typename S> void assertsCpp(S soln) {
  for (auto &row : table) {
    TreeNode *root1 = construct_binary_tree(row.root1);
    TreeNode *root2 = construct_binary_tree(row.root2);
    TreeNode *root = soln.mergeTrees(root1, root2);
    cout << "CHECK: " << row.root1 << endl;
    cout << root << endl;
    CHECK(root == row.expected);
    free_tree(root);
  }
}

TEST_CASE("c solutions") { assertsC(); }
TEST_CASE("c solutions") { assertsCpp(Solution()); }
