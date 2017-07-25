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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> nums, tmp;

        if (root == NULL)
          return nums;

        nums.push_back(root->val);

        if (root->left != NULL) {
          tmp = preorderTraversal(root->left);
          for (int j = 0; j < tmp.size(); j++)
            nums.push_back(tmp[j]);
        }

        if (root->right != NULL) {
          tmp = preorderTraversal(root->right);
          for (int j = 0; j < tmp.size(); j++)
            nums.push_back(tmp[j]);
        }

        return nums;
    }
};
