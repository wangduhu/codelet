#include <stdlib.h>
#include "binary_treenode.h"

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL) {
        return root2;
    }
    if (root2 == NULL) {
        return root1;
    }
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

/*
  Status: Accepted (182/182)
  Runtime: 37 ms, faster than 66.93% of C submissions.
  Memory Usage: 14.4 MB, less than 74.32% of C submissions.
 */
