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
        if (root) {
            TreeNode* T = (TreeNode*)malloc(sizeof(TreeNode));
            T->val = root->val;
            T->left = cloneTree(root->left);
            T->right = cloneTree(root->right);

            return T;
        } else {
            return NULL;
        }
    }
};
