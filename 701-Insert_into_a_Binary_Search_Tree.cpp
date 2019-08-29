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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return helper(root, val);
    }
    
    TreeNode* helper(TreeNode* root, int val){
        if(root==NULL){
            root = new TreeNode (val);
            return root;
        }
        
        if(root->val > val)
            root->left = helper(root->left, val);
        else
            root->right = helper(root->right, val);       
        
        return root;
    }
    
};
