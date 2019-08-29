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
        bool bst;
        int min;
        int max;
    };
    
    bool isValidBST(TreeNode* root) {
        // divided conquer
        // left side maximum need to be less than root
        // right side minimum need to be larger than root
        result final_res = helper(root);
        return final_res.bst;
    }
    
    result helper(TreeNode* root){ // get min and max
        result res;
        if(!root){
            
            cout << "come to NULL root part" << std::endl;
            
            res.bst = true;
            res.min = 32767; // hard part
            res.max = -32767;
            return res;
        }
        
        cout << "come to root value is " << to_string(root->val) <<std::endl;
        
        
        result left = helper(root->left);
        cout << "come to root left part" << std::endl;
        
        result right = helper(root->right);
        cout << "come to root right part" << std::endl;
        
        if(left.bst==false || right.bst == false){
            res.bst = false;
            cout << "come to root bst false part" << std::endl;
            return res;
        }
        
        if( (root->left!= NULL && left.max >= root->val ) // hard part
           || (root->right!=NULL && right.min<= root->val ) ){
            res.bst = false;
            cout << "come to value false part" << std::endl;
            return res;
        }
        
        res.bst = true;
        res.min = min(left.min, root->val); // hard part
        res.max = max(right.max,root->val);
        cout << "min is " << to_string(res.min) <<std::endl;
        cout << "max is " << to_string(res.max) <<std::endl;
        
        cout << "come corret part" << std::endl;
        
        
        return res;
    }
};



/*
 
 class Solution {
 public:
 bool isValidBST(TreeNode* root) {
 // traverse and inorder
 TreeNode* pre = NULL; // this is for first node case
 return inorder(root, pre);
 }
 
 bool inorder(TreeNode* node, TreeNode* &pre){ // pay attention to &pre
 if(node == NULL)
 return true;
 
 bool result;
 result = inorder(node->left, pre); // check left side is inorder
 if(!result)
 return false;
 
 if(pre){
 if(pre->val>= node->val)
 return false;
 }
 pre = node;
 
 return inorder(node->right, pre);
 }
 };
 
 */
