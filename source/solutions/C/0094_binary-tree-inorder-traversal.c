/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
  if (root == NULL) {
    *returnSize = 0;
    return NULL;
  }
  int lsize, rsize;
  int* larr = inorderTraversal(root->left, &lsize);
  int* rarr = inorderTraversal(root->right, &rsize);

  *returnSize = lsize + rsize + 1;
  int * arr = (int *)malloc(*returnSize * sizeof(int));
  if (larr) {
    memcpy(arr, larr, sizeof(int) * lsize);
  }
  arr[lsize] = root->val;
  if (rarr) {
    memcpy(arr + lsize + 1, rarr, sizeof(int) * rsize);
  }

  free(larr);
  free(rarr);

  return arr;
}
