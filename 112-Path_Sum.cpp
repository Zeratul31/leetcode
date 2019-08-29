/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        
        if(!root->left && !root->right){
            if(root->val ==sum)
                return true;
            else
                return false;
        }
        
        bool left_res = false, right_res = false;
        
        if(root->left){
            left_res = hasPathSum(root->left, sum - root->val);
        }
        if(root->right){
            right_res = hasPathSum(root->right, sum - root->val);
        }
        
        if(left_res||right_res)
            return true;
        else
            return false;
    }
};
