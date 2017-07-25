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
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        if (root == NULL)
          return NULL;

        TreeNode *node_clone;
        node_clone->val = root->val;
        if (root->left == NULL)
          node_clone->left = NULL;
        else
          node_clone->left = cloneTree(root->left);
        if (root->right == NULL)
          node_clone->right = NULL;
        else
          node_clone->right = cloneTree(root->right);

        return node_clone;
    }
};
