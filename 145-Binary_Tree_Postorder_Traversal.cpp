
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> result;
        if(!root) return result;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode *node = stack.top();
            if(!node->left&&!node->right) {
                result.push_back(node->val);
                stack.pop();
            }
            if(node->right) {
                stack.push(node->right);
                node->right = NULL;
            }
            if(node->left) {
                stack.push(node->left);
                node->left = NULL;
            }
        }
        return result;
        
    };
};

/*
 
 class Solution {
 public:
 vector<int> postorderTraversal(TreeNode* root) {
 helper(root);
 return result;
 }
 
 void helper(TreeNode* root){
 if(root ==NULL)
 return;
 
 helper(root->left);
 helper(root->right);
 result.push_back(root->val);
 
 return;
 }
 
 private:
 vector<int> result;
 };
 
 */
