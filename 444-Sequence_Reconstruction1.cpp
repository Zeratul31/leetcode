
class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        // use method of Topological sort
        unordered_map <int, unordered_set<int>> neighbor_map;
        unordered_map <int, int> indegree;
        
        if(seqs.empty())
            return false;
        
        if(org.size()==0 && seqs[0].size()==0)
            return true;
        
        if (org.empty() || seqs[0].empty())
            return false;// handle coner case
        
        for(int i=0; i<org.size(); i++){
            unordered_set<int> temp_set;
            indegree.emplace(i,0);
            neighbor_map.emplace(i,temp_set);
        }
        
        // record neighbor map and indegree map
        for(auto seq: seqs){
            for(int i=0; i< seq.size()-1; i++){// carefull about size
                if(neighbor_map[seq[i]].find(seq[i+1]) == neighbor_map[seq[i]].end() ){ // carefull about neighbor_map[seq[i]] format
                    neighbor_map[seq[i]].emplace(seq[i+1]); // add neighbour
                    
                    if(indegree.find(seq[i+1]) == indegree.end())
                        indegree.emplace(seq[i+1],1);
                    else
                        indegree[seq[i+1]]++;
                }
            }
        }
        
        queue<int> queue;
        int index = 0;
        
        for(int i=1; i<=org.size(); i++){ // special for this problem
            if(indegree[i]==0)
                queue.push(i);
        }
        
        while(queue.size()==1){ // should be only one int at queue each time
            int temp = queue.front();
            cout << "debug " << to_string(temp) << endl;
            queue.pop();
            
            if(org[index]!=temp) // make sure the order is same for org and generated seq
                return false;
            
            index++; // careful for index
            
            for(auto neighbor: neighbor_map[temp]){
                indegree[neighbor]--;
                
                if(indegree[neighbor] == 0)
                    queue.push(neighbor);
            }
        }
        cout << "index " << to_string(index) << endl;
        return (index == org.size());
    }
};
