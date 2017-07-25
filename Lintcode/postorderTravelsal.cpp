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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> nums, tmp;

        if (root == NULL) {
          return nums;
        }

        if (root->left != NULL)
          nums = postorderTraversal(root->left);

        if (root->right != NULL) {
          tmp = postorderTraversal(root->right);
          for (int j = 0; j < tmp.size(); j++)
            nums.push_back(tmp[j]);
        }

        nums.push_back(root->val);

        return nums;
    }
};
