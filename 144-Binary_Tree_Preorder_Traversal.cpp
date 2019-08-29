
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // iteratively
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> sta;
        
        if(root == NULL)
            return result;
        
        sta.push(root);
        
        while(!sta.empty()){
            TreeNode* node;
            node = sta.top();
            result.push_back(node->val);
            sta.pop();
            
            if(node->right)
                sta.push(node->right);
            
            if(node->left)
                sta.push(node->left);
        }
        return result;
    }
};

/*
 class Solution { // recursive traverse
 public:
 vector<int> preorderTraversal(TreeNode* root) {
 helper(root);
 return result;
 }
 
 void helper(TreeNode* root){
 if(root ==NULL)
 return;
 
 result.push_back(root->val);
 
 helper(root->left);
 helper(root->right);
 
 return;
 }
 
 private:
 vector<int> result;
 };
 
 */
