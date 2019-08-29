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
    int minDepth(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int left = 32767, right = 32767;
        
        if(!root->left && !root->right) // careful for no leaf case
            return 1;
        
        if(root->left)
            left = minDepth(root->left);
        
        if(root->right)
            right = minDepth(root->right);
        
        
        if(left <  right)
            return left + 1;
        else
            return right + 1;
    }
    
};


/*
 
 class Solution {
 public:
 int minDepth(TreeNode* root) {
 if(root == NULL)
 return 0;
 
 int min_left_depth = minDepth(root->left);
 int min_right_depth = minDepth(root->right);
 
 if(min_left_depth == 0) // careful for no leaf case
 return (min_right_depth + 1);
 else if(min_right_depth == 0)
 return (min_left_depth + 1);
 else
 {
 if (min_left_depth < min_right_depth)
 return (min_left_depth + 1);
 else
 return (min_right_depth + 1);
 }
 }
 };
 
 */
