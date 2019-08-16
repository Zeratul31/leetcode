class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        if(n==0)
            return false;
        
        if(edges.size()!=n-1)
            return false;
        
        unordered_map<int, unordered_set<int>> graph = initial_graph(n,edges);//generate Adjacency list
        
        if(n==1 && graph[0].empty())
            return true;
        
        // bfs
        // 1. to judge there is no islated point which dose not connect to any point. 2. judge there are no islated few points which not connect to other points
        queue<int> crt_queue;
        unordered_set<int> hash;
        
        crt_queue.push(0);
        hash.emplace(0);
        
        while (!crt_queue.empty()){
            int node = crt_queue.front();
            crt_queue.pop();
            for(auto neighbor: graph[node]){
                if(hash.find(neighbor)!=hash.end())
                    continue;
                
                hash.emplace(neighbor);
                crt_queue.push(neighbor);
            }
        }
        return (hash.size()==n);
        
    }
    
private:
    unordered_map<int, unordered_set<int>> initial_graph(int n,vector<vector<int>>edges){
        unordered_map<int, unordered_set<int>> result_map;
        for(int i=0;i<n;i++){
            unordered_set<int> current_vertex_connection;
            
            for(int j = 0; j < edges.size(); j++){
                if(edges[j][0] == i){
                    current_vertex_connection.emplace(edges[j][1]);
                }
                else if(edges[j][1] == i){
                    current_vertex_connection.emplace(edges[j][0]);
                }
            }
            result_map.emplace(i,current_vertex_connection);
        }
        return result_map;
    }
};
