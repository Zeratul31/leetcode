
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
    struct result{
        int sum;
        int tilt;
    };
    
    int findTilt(TreeNode* root) {
        return helper(root).tilt;
    }
    
    result helper(TreeNode* root){
        result res;
        result left_m;
        result right_m;
        
        if(!root){
            res.sum=0;
            res.tilt = 0;
            return res;
        }
        
        left_m = helper(root->left);
        right_m = helper(root->right);
        
        res.sum = left_m.sum + right_m.sum + root->val;
        res.tilt = abs(left_m.sum - right_m.sum) + left_m.tilt + right_m.tilt;
        
        return res;
    }
};
