/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        vector<ListNode*> result;
        if(root==NULL)
            return result;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            int q_size = queue.size();
            ListNode* pre_node;
            
            for(int i=0; i<q_size; i++){
                TreeNode* node = queue.front();
                queue.pop();
                
                if(i==0){
                    pre_node = new ListNode(node->val);// grammar !!
                    result.push_back(pre_node);
                }
                else{
                    pre_node->next = new ListNode(node->val);// grammar !!
                    pre_node = pre_node->next;
                }
                
                if(node->left)
                    queue.push(node->left);
                
                if(node->right)
                    queue.push(node->right);
            }
            
            pre_node->next = NULL;
        }
        return result;
    }
};


