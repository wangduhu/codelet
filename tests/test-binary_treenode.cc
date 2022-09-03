#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include <cassert>

#include "binary_treenode.h"


using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("solution") {
    TreeNode* root = construct_binary_tree({"3", "9", "20", "#", "#", "15", "7"});
    // cout << root << endl;
    CHECK(root->height() == 3);
    CHECK(root->preorder() == vector<int>({3, 9, 20, 15, 7}));
    CHECK(root->inorder() == vector<int>({9, 3, 15, 20, 7}));
    CHECK(root->inorder() == root->inorder_iterative());
}
