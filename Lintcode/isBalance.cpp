/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if (root == NULL)
          return true;

        if ( abs( depth(root->left) - depth(root->right) ) > 1 )
          return false;

        if (isBalanced(root->left) && isBalanced(root->right))
          return true;
        else
          return false;
    }

    int depth(TreeNode *root) {
      if (root == NULL)
        return 0;
      return max( depth(root->left), depth(root->right) ) + 1;
    }
};
