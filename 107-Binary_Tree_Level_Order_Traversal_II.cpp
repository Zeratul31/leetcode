
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // bfs and reverse result OR insert result into the begin part
        
        vector<vector<int>> result;
        
        if(root==NULL)
            return result;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            vector<int> temp;
            int q_size = queue.size();
            for(int i=0; i<q_size;i++){
                TreeNode* node = queue.front();
                queue.pop();
                temp.push_back(node->val);
                
                if(node->left)
                    queue.push(node->left);
                
                if(node->right)
                    queue.push(node->right);
            }
            result.insert(result.begin(),temp); // insert part
        }
        return result;
    }
};
