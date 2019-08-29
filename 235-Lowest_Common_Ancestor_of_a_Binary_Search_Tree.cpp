
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if p and q is under root, return lca(p, q)
        // if only p under root, return p
        // if only q under root, return q
        // if none under root, return NULL
        
        if(root == NULL || root ==p || root == q)
            return root;
        
        TreeNode *left_root = lowestCommonAncestor(root->left, p, q);
        TreeNode *right_root = lowestCommonAncestor(root->right, p, q);
        
        if(left_root && right_root) // root is lca now
            return root;
        
        if(left_root)  // only find p or q
            return left_root;
        
        if(right_root) // only find p or q
            return right_root;
        
        return NULL; // left and right all null
    }
};
