/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        //count indegree for all nodes
        vector<DirectedGraphNode*> result;
        if(graph.size() == 0)
            return result;
        
        unordered_map<DirectedGraphNode*, int> indegree_map;
        for(auto node: graph){
            for(auto nb_node: node->neighbors){
                if(indegree_map.find(nb_node)!= indegree_map.end())
                    indegree_map[nb_node] = indegree_map[nb_node] + 1;
                else
                    indegree_map.emplace(nb_node,1);
            }
        }
        
        //bfs indegree = 0 nodes
        queue<DirectedGraphNode*> que_node;
        
        
        for(auto node: graph){
            if(indegree_map.find(node)==indegree_map.end()){
                que_node.push(node);
                result.push_back(node);
            }
        }
        
        // bfs queue
        while(!que_node.empty()){
            DirectedGraphNode* node_temp;
            node_temp = que_node.front();
            que_node.pop();
            
            for(auto neighbor: node_temp->neighbors){
                if(indegree_map.find(neighbor)!=indegree_map.end()){
                    indegree_map[neighbor] = indegree_map[neighbor] - 1;
                    
                    if(indegree_map[neighbor] == 0){
                        indegree_map.erase(neighbor);
                        que_node.push(neighbor);
                        result.push_back(neighbor);
                    }
                }
            }
            
        }
        
        if(!indegree_map.empty()) // 0-->1-->2-->3 and 3-->1 there is a circle inside graph
            result.clear();
        
        return result;
    }
};
