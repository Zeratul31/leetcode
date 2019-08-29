/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // iteratively using stack
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> root_s;
        
        while(1){
            
            if(root!=NULL){
                root_s.push(root);
                root = root->left;
            }
            else{
                if(root_s.empty()) break;
                TreeNode* node = NULL;
                node = root_s.top();
                result.push_back(node->val);
                root_s.pop();
                root = node->right; // hard part is "node"
            }
        }
        
        
        return result;
    }
};

/*
 class Solution { // Recursive
 public:
 vector<int> inorderTraversal(TreeNode* root) {
 helper(root);
 return result;
 }
 
 void helper(TreeNode* root){
 if(root==NULL)
 return;
 
 helper(root->left);
 result.push_back(root->val);
 helper(root->right);
 }
 
 private:
 vector<int> result;
 };
 */
