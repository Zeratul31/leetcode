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
    int unbalanced = -1;
    
    bool isBalanced(TreeNode* root) {
        int result = depth_helper(root);
        if (result == -1)
            return false;
        else
            return true;
    }
    
    int depth_helper(TreeNode* root){ // without using struct. use -1 instead
        
        if(!root)
            return 0;
        
        int left = depth_helper(root->left);
        int right = depth_helper(root->right);
        
        if( left== unbalanced || right == unbalanced || abs(left - right) > 1  )
            return -1;
        else
            return max(left, right) + 1;
    }
};

/*
 
 class Solution {
 public:
 
 struct result{
 int depth;
 bool balanced;
 };
 
 bool isBalanced(TreeNode* root) {
 return helper(root).balanced;
 }
 
 result helper(TreeNode* root){ //using struct to record depth and bool balanced
 result m_res;
 
 if(!root){
 m_res.balanced = true;
 m_res.depth = 0;
 return m_res;
 }
 
 result left_r = helper(root->left);
 result right_r = helper(root->right);
 
 if( !left_r.balanced || !right_r.balanced )
 {
 m_res.balanced = false;
 }else if( abs(left_r.depth - right_r.depth) >1 )
 {
 m_res.balanced = false;
 }else{
 m_res.balanced = true;
 m_res.depth = (max(left_r.depth, right_r.depth) + 1);
 }
 
 return m_res;
 }
 
 };
 
 
 */
