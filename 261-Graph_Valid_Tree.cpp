class Solution {
public:
/**
* @param n: An integer
* @param edges: a list of undirected edges
* @return: true if it's a valid tree, or false
*/
bool validTree(int n, vector<vector> &edges) {
// write your code here

    //条件一：n个node， n-1个edge
    if( static_cast<int>(edges.size()) != n - 1) { return false; }
    
    //convert 成 adjecent list 形式 graph a
    std::unordered_map<int,std::unordered_set<int>> Graph_In {toGraph(n,edges)};
    // Record 已经connected 的 vertex
    std::unordered_set<int> recorded_node;
    // iterator
    std::unordered_map<int,std::unordered_set<int>>::const_iterator it;
    //Check graph
    /*for (auto& i : Graph_In) {
        std::cout << i.first <<" 111111"<<std::endl;
        for (auto &j : i.second) {
            std::cout << j << std::endl;
        }
    }*/
    // Bfs queue 去iterate 每一个 node 和 他的 connection
    std::queue<int> current_levelNode;
    // Push root
    current_levelNode.push(0);
    
    // BFS while
    while(!current_levelNode.empty()){
        
        int current_vertex {current_levelNode.front()};
        current_levelNode.pop();
        
        // Record 有了就不加入
        if(recorded_node.find(current_vertex) == recorded_node.end()){
            recorded_node.emplace(current_vertex);   
        }
        //找到 graph（adjacent list的 node hash set）
        it = Graph_In.find(current_vertex);
        for (auto &i : it->second) {
            //对于这个 vertex 的 hashset 来说， 如果record 里面没有， 把新的connected vertex 加入
            if(recorded_node.find(i) == recorded_node.end()){
                
                recorded_node.emplace(i);
                //把没有iterate through 的vertex加入 queue ，拓展新vertex里面的connection
                current_levelNode.push(i);
                
            }
            
        }
        
    }
    
    if( static_cast<int>(recorded_node.size()) == n){ return true; }
    return false;
}

std::unordered_map<int,std::unordered_set<int>> toGraph(int n,std::vector<std::vector<int>> &edges){

    std::unordered_map<int,std::unordered_set<int>> result_graph;
    
    for(int i = 0; i < n; i++)
    {

        std::unordered_set<int> current_vertex_connection;

        for(int j = 0; j < edges.size(); j++)
        {

            if(edges[j][0] == i){

                current_vertex_connection.emplace(edges[j][1]);

            }
            else if(edges[j][1] == i){

                current_vertex_connection.emplace(edges[j][0]);

            }
            
        }
        result_graph.emplace(i,current_vertex_connection);

    }
    
    return result_graph;
}
};
