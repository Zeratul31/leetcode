
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
    void flatten(TreeNode* root) {
        // divided conquer
        helper(root);
    }
    
    TreeNode* helper(TreeNode* root){ // return last treenode in one side
        
        if(!root)
            return NULL;
        
        TreeNode* lastleft = helper(root->left);// return last treenode in left side
        TreeNode* lastright = helper(root->right);
        
        if(lastleft){ // hard part
            lastleft->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        
        if(lastright)
            return lastright;
        
        if(lastleft)
            return lastleft;
        
        return root;
    }
};


/*
 
 class Solution {
 public:
 TreeNode* lastnode = NULL;
 void flatten(TreeNode* root) {
 // traverse preorder
 
 if(!root)
 return;
 
 if(lastnode!= NULL){
 lastnode->left = NULL;
 lastnode->right = root;
 // because we need to move this root to right of last node, so in line25 we need to create a temp node to save last node right side.
 //otherwise, lastnode->right will updated by root-> left
 //in this example: we need to move 2 to 1->right side. so we need to keep 5 in temp node
 }
 
 lastnode = root;
 TreeNode* right = root->right; // hard part
 flatten(root->left);
 flatten(right);
 }
 };
 
 
 
 */
