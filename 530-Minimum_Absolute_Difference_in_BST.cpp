
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
    int getMinimumDifference(TreeNode* root) {// this is binary search tree !
        int result = INT_MAX;
        int pre = -1;
        
        inorder(root, pre, result);
        return result;
    }
    
    void inorder(TreeNode* root, int& pre, int&res){
        if(!root)
            return;
        
        inorder(root->left, pre, res);
        
        if(pre!=-1){
            res = min(res, abs(root->val - pre));
        }
        
        pre = root->val;
        
        inorder(root->right, pre, res);
    }
    
};
