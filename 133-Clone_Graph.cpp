
/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 vector<Node*> neighbors;
 
 Node() {}
 
 Node(int _val, vector<Node*> _neighbors) {
 val = _val;
 neighbors = _neighbors;
 }
 };
 */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        // method of BFS
        if(node == NULL)
            return NULL;
        
        unordered_map<Node*, Node*> hashmap;        //旧节点和新节点的映射
        queue<Node*> q;
        //注意克隆时不管是节点还是邻居，都得新建，新加入邻居，不能用原来的直接复制，否则就不是新的节点、邻居了
        Node* clone = new Node(node->val, vector<Node*>() ); // be careful for grammar
        hashmap[node] = clone;
        q.push(node);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            for(auto cur: temp->neighbors){
                if(hashmap.find(cur)==hashmap.end()){
                    hashmap[cur] = new Node(cur->val, vector<Node*>());
                    q.push(cur);
                }
                // hashmap[temp]->neighbors.push_back(cur); //wrong. we need to deep copy its neighbor, too
                hashmap[temp]->neighbors.push_back(hashmap[cur]);
            }
        }
        
        return clone;
    }
};
