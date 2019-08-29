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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        int min = root->val;
        sec_min = -1;
        
        helper(root);
        
        if(sec_min == -1)
            return -1;
        else
            return sec_min;
    }
    
    void helper(TreeNode* root){
        if(root->left == NULL)
            return;
        
        if(root->left->val != root->right->val){
            int temp = max(root->left->val, root->right->val);
            if(sec_min == -1)
                sec_min = temp;
            else
                sec_min = min(sec_min,temp);
        }
        
        helper(root->left);
        helper(root->right);
        return;
    }
    
private:
    int sec_min;
};
