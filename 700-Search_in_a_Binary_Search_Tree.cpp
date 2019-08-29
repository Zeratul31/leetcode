
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        
        if(root->val == val){
            cout << "come to 111" << std::endl;
            return root;
        }
        
        if(root->val > val){
            cout << "come to 222" << std::endl;
            return searchBST(root->left, val);
        }
        else{
            cout << "come to 333" << std::endl;
            return searchBST(root->right, val);
        }
    }
};
