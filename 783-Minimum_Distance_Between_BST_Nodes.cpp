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
    int minDiffInBST(TreeNode* root) {
        // need last to record last root val
        // need res to record min diff
        int last = -1;
        int res = INT_MAX;
        helper(root, last, res);
        return res;
    }
    
    void helper(TreeNode* root, int& last, int& res){
        if(!root)
            return;
        
        helper(root->left, last, res); // left, root, right order. this is BST!
        
        if(last!=-1){
            res = min(res, abs(root->val - last));
        }            
        
        last = root->val;
        
        helper(root->right, last, res);
        return;
    }
};
