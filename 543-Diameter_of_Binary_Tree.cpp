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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        depth(root, result);
        return result;
    }
    
    int depth(TreeNode* root, int& res){
        if(!root)
            return 0;
        
        int left = depth(root->left, res);
        int right = depth(root->right, res);
        
        res = max(res, left+right); // final diameter is max (diameter of left and right and depth sum of left +right)
        return max(left, right) + 1;
    }
    
};
