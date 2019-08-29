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
    int depth = 0;
    
    int maxDepth(TreeNode* root) {
        //traverse
        
        helper(root, 1);
        return depth;
    }
    
    void helper(TreeNode* root, int current_depth){
        if(!root)
            return;
        
        if(current_depth > depth)
            depth = current_depth;
        
        helper(root->left, current_depth+1);
        helper(root->right, current_depth+1);
    }
};

/*
 class Solution {
 public:
 int maxDepth(TreeNode* root) {
 //divide and conquer
 
 if(!root)
 return 0;
 
 int left = maxDepth(root->left);
 int right = maxDepth(root->right);
 
 if(left>right)
 return left + 1;
 else
 return right + 1;
 
 // time limit exceeded error !
 //        if(maxDepth(root->left)>maxDepth(root->right))
 //            return maxDepth(root->left) + 1;
 //        else
 //            return maxDepth(root->right) + 1;
 
 }
 };
 
 
 */



