class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==1){
            if(prerequisites.size()==0 || prerequisites[0].size()==0)
                return true;
            else
                return false;
        }
        
        if(numCourses ==0 || numCourses==1){
            // if(prerequisites.size()==0 || prerequisites[0].size() ==0)
            return false;
        }
        
        unordered_map<int, unordered_set<int>> neighbor_map;
        unordered_map<int, int> indegree;
        for(int i=0; i< numCourses; i++){
            indegree.emplace(i,0);
        }
        
        for (auto pair: prerequisites){// create neighbor map and indegree map
            if(pair.size()!=2)
                return false;
            
            if(neighbor_map[pair[1]].find(pair[0])==neighbor_map[pair[1]].end())
            {
                neighbor_map[pair[1]].emplace(pair[0]);
                
                if(indegree.find(pair[1])==indegree.end())
                {
                    indegree.emplace(pair[0],1);
                    // cout<< "debug" << to_string(pair[1]) << endl;
                    // cout<< "debug indegree" << to_string(indegree[pair[1]]) << endl;
                }
                else{
                    indegree[pair[0]]++; // add indegree to neighbor not root!!
                    // cout<< "not come indegree" << to_string(indegree[pair[1]]) << endl;
                    // cout<< "not come"  << endl;
                }
            }
        }
        
        queue<int> queue;
        
        for(int i=0; i<numCourses; i++){
            // cout<< "not come indegree" << to_string(indegree[i] ) << endl;
            if(indegree[i]==0)
                queue.push(i);            
        }
        int index=0;
        
        while(!queue.empty()){
            int temp = queue.front();
            queue.pop();
            index++;
            
            // cout<< "temp" << to_string(temp) << endl;
            // cout<< "map size" << to_string(neighbor_map[0].size()) << endl;
            
            for(auto nb: neighbor_map[temp]){
                indegree[nb]--;
                // cout<< "indegree nb" << to_string(indegree[nb]) << endl;
                
                if(indegree[nb]==0)
                    queue.push(nb);
            }
            
        }
        // cout<< "index" << to_string(index) << endl;
        
        return (numCourses == index);
    }
};
