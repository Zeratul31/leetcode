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
    int rangeSumBST(TreeNode* root, int L, int R) {
        // if root val >R, traverse for left side
        // if root val =R, sum = sum + root val and traverse for left side
        // if root L< val <R, sum = sum + root val and traverse for both side
        // if root val =L, sum = sum + root val and traverse for right side
        // if root val <L, traverse for right side
        if(!root)
            return 0;
        
        if(root->val>=L && root->val<=R)
            sum = sum + root->val;
        
        if(root->val>L && root->left)
            rangeSumBST(root->left, L, R);
        
        if(root->val<R && root->right)
            rangeSumBST(root->right, L, R);
        
        // cout << "debug output is" << to_string(sum) << std::endl;
        
        return sum;
    }
    
private:
    int sum = 0;    
};
