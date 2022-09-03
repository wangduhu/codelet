#include "binary_treenode.h"

TreeNode* construct_binary_tree(const std::vector<std::string> repr) {
  if (repr.empty()) {
    return nullptr;
  }

  std::vector<TreeNode*> nodes;
  for(auto s : repr) {
    if (s == "#") nodes.push_back(nullptr);
    else nodes.push_back(new TreeNode(atoi(s.c_str())));
  }
  int len = nodes.size();
  for (size_t i = 0; i < len / 2; i++) {
    int left = 2*i + 1;
    if (left < len && nodes[left]) {
      nodes[i]->left = nodes[left];
      nodes[left]->parent = nodes[i];
    }
    int right = 2*i + 2;
    if (right < len && nodes[right]) {
      nodes[i]->right = nodes[right];
      nodes[right]->parent = nodes[i];
    }
  }
  return nodes[0];
}

void free_tree(TreeNode* root) {
  if (root == nullptr) return;
  free_tree(root->left);
  free_tree(root->right);
  delete root;
}

// 前序遍历打印
std::ostream& operator<<(std::ostream& out, TreeNode* root) {
  if (root) {
    out << root->val << ' ';
    out << root->left;
    out << root->right;
  }
  return out;
}

bool operator== (TreeNode* root, std::vector<int> nums) {
  return root->preorder() == nums;
}

TreeNode* deepcopy(TreeNode* root) {
  if (root == nullptr) return root;
  TreeNode* node = new TreeNode(root->val);
  node->left = deepcopy(root->left);
  node->right = deepcopy(root->right);
  return node;
}
