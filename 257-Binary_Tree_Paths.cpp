
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
    vector<string> binaryTreePaths(TreeNode* root) {
        // traverse
        vector<string> all_path;
        
        if(!root)
            return all_path;
        
        helper(root, to_string(root->val), all_path);
        
        return all_path;
    }
    
    void helper(TreeNode* root, string path ,vector<string> &all_path){
        //cout << "path is" << path << std::endl;
        
        if(!root)
            return;
        
        if(!(root->left) && !(root->right)){
            all_path.push_back(path); // hard part
            return;
        }
        
        if(root->left)
            helper(root->left, path + "->" + to_string(root->left->val), all_path);
        
        if(root->right)
            helper(root->right, path + "->" + to_string(root->right->val), all_path);
    }
    
};


/*
 class Solution {
 public:
 vector<string> binaryTreePaths(TreeNode* root) {
 // divide conquer
 
 vector<string> result;
 
 if(!root)
 return result; // empty result
 
 if(!root->left && !root->right)
 result.push_back(to_string(root->val));// leaf case: add val in result
 // return result;
 
 vector<string> left_path = binaryTreePaths(root->left);
 vector<string> right_path = binaryTreePaths(root->right);
 
 for(auto temp: left_path)
 result.push_back( to_string(root->val) + "->" + temp);
 
 for(auto temp: right_path)
 result.push_back( to_string(root->val) + "->" + temp);
 
 return result;
 }
 
 */

