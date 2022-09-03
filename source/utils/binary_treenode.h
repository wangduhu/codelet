#ifndef _BINARY_TREENODE_H_
#define _BINARY_TREENODE_H_

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include <cstdlib>

#include "common.h"


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode* next;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr), next(nullptr) {}

    int height() {
        if (left == nullptr && right == nullptr) return 1;
        if (left == nullptr) return right->height() + 1;
        if (right == nullptr) return left->height() + 1;
        return std::max(left->height(), right->height()) + 1;
    }

    void preorder(TreeNode* root, std::vector<int>& nums) {
        if (root == nullptr) return;
        nums.push_back(root->val);
        preorder(root->left, nums);
        preorder(root->right, nums);
    }

    std::vector<int> preorder() {
        std::vector<int> nums;
        preorder(this, nums);
        return nums;
    }

    void inorder(TreeNode* root, std::vector<int>& nums) {
        if (root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }


    std::vector<int> inorder() {
        std::vector<int> nums;
        inorder(this, nums);
        return nums;
    }

    std::vector<int> inorder_iterative() {
        std::vector<int> nums;
        std::stack<TreeNode*> s;
        TreeNode* cur = this;
        while (true) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty()) break;
            cur = s.top();
            s.pop();
            nums.push_back(cur->val);
            cur = cur->right;
        }
        return nums;
    }
};




/* {3,9,20,#,#,15,7},
   3
   / \
   9 20
   / \
   15 7
*/
TreeNode* construct_binary_tree(const std::vector<std::string> repr);
void free_tree(TreeNode* root);
// 前序遍历打印
std::ostream& operator<<(std::ostream& out, TreeNode* root);
bool operator== (TreeNode* root, std::vector<int> nums);
TreeNode* deepcopy(TreeNode* root);

#endif
