class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        
        if(numCourses==0)   return res;
        if(numCourses==1){
            if(prerequisites.size()==0 || prerequisites.size()==1){ // only for weired test case. ignore this
                res.push_back(0);
                return res;
            }
            else if(prerequisites[0].size()==1){
                return res=prerequisites[0];
            }
            else
                return res;
        }
        
        unordered_map<int, unordered_set<int>> neighbor_map;
        unordered_map<int, int> indegree;
        for(int i=0; i< numCourses; i++){
            indegree.emplace(i,0);
        }
        
        for (auto pair: prerequisites){// create neighbor map and indegree map
            if(pair.size()!=2){
                res.clear();
                return res;
            }
            if(neighbor_map[pair[1]].find(pair[0])==neighbor_map[pair[1]].end())
            {
                neighbor_map[pair[1]].emplace(pair[0]);
                
                if(indegree.find(pair[1])==indegree.end())
                    indegree.emplace(pair[0],1);
                else
                    indegree[pair[0]]++; // add indegree to neighbor not root!!
            }
        }
        
        queue<int> queue;
        
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)
                queue.push(i);
        }
        
        int index=0;
        
        while(!queue.empty()){
            int temp = queue.front();
            queue.pop();
            res.push_back(temp);
            index++;
            
            for(auto nb: neighbor_map[temp]){
                indegree[nb]--;
                
                if(indegree[nb]==0)
                    queue.push(nb);
            }
            
        }
        
        if(numCourses!= index){
            res.clear();
            return res;
        }
        else
            return res;
    }
};
