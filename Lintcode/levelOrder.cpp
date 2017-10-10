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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> vec;
        if(!root){
            return vec;
        }
         
        queue<TreeNode*> que;
        que.push(root);
         
        while(!que.empty()){
             
            int count=que.size();
            vector<int> vec_temp;
             
            while(count--){
                TreeNode* temp=que.front();
                que.pop();
                vec_temp.push_back(temp->val);
                 
                if(temp->left){
                    que.push(temp->left);
                }
                 
                if(temp->right){
                    que.push(temp->right);
                }
            }
            vec.push_back(vec_temp);
        }
        // reverse(vec.begin(),vec.end());
        return vec;
    }
};
