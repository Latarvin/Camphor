class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        if (root == NULL) return NULL;

        if (root->left == NULL || root->right == NULL) {
            return root;
        } else if (root->left == NULL) {
            if (root->val > maxNode(root->right)->val)
                return root;
            else
                return root->right;
        } else if (root->right == NULL) {
            if (root->val > maxNode(root->left)->val)
                return root;
            else
                return root->left;
        } else if (root->val > maxNode(root->left)->val) {
            if (root->val > maxNode(root->right)->val)
                return root;
            else
                return root->right;
        } else {
            return root->left;
        }
    }
};
