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
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return false;              
        
        bool left_res = true, right_res = true;
        
        if(root->left){
            if(root->val == root->left->val)
                left_res = isUnivalTree(root->left);
            else
                return false;
        }
        
        if(root->right){
            if(root->val == root->right->val)
                right_res = isUnivalTree(root->right);
            else
                return false;
        }            
        
        if(left_res && right_res)
            return true;
        else
            return false;
    }
};
