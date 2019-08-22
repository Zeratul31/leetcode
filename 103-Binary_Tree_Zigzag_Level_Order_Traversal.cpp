
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        
        queue<TreeNode*> queue;
        queue.push(root);
        int flag = -1;
        
        while(!queue.empty()){
            int q_size = queue.size();
            vector<int> temp;
            flag++;
            for(int i=0; i< q_size; i++){
                TreeNode* node = queue.front();
                queue.pop();
                
                if(flag%2 == 0)
                    temp.push_back(node->val);
                else
                    temp.insert(temp.begin(),node->val);
                
                if(node->left)
                    queue.push(node->left);
                
                if(node->right)
                    queue.push(node->right);
            }
            result.push_back(temp);
        }
        return result;
    }
};
