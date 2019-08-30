class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {// BFS (end to start) + DFS (start to end) !!
        // prepare        
        vector<vector<string>> res;
        unordered_set<string> dict;
        for(auto i: wordList)
            dict.emplace(i);
        
        dict.emplace(beginWord);
        
        // corner case
        if(dict.find(endWord)==dict.end() || wordList.size()==0)
            return res;
        
        unordered_map<string, int> distance;
        unordered_map<string, unordered_set<string>> neighbor;
        
        BFS(beginWord, endWord, dict, distance, neighbor);// bfs
        
        vector<string> path;
        path.push_back(beginWord);
        DFS(beginWord, endWord, distance, neighbor, res, path);// dfs
        
        return res;
    }
    
private:
    void BFS(string beginWord, string endWord, unordered_set<string> &dict, unordered_map<string, int> &distance, unordered_map<string, unordered_set<string>> &neighbor){
        queue<string> queue;
        queue.push(endWord);
        int dstc = 1;
        distance.emplace(endWord,0);
        
        while(!queue.empty()){
            int q_size = queue.size();
            
            for(int i=0; i<q_size; i++){
                string temp = queue.front();
                queue.pop();
                
                for(auto nei: get_neighbor(temp, dict))//traverse temp's all valid nei
                {
                    if(distance.find(nei)==distance.end()){
                        distance.emplace(nei, dstc);
                        // cout<< "BFS distance for: "<<nei<<" is: "<<to_string(dstc) <<endl;
                        
                        queue.push(nei);                       
                    }
                    neighbor[temp].emplace(nei);
                    // cout<< "BFS neighbor for: " <<temp<<" is: "<<nei <<endl;
                    
                }
                
                if(temp == beginWord)
                    return;
            }
            dstc++;
        }
    }
    
    void DFS(string current, string endWord, unordered_map<string, int> &distance, unordered_map<string, unordered_set<string>> &neighbor, vector<vector<string>> &res, vector<string> &path){
        if(current == endWord){
            res.push_back(path);    
            return;
        }
        
        // for(int i=0; i<neighbor(current).size(); i++){
        for(auto nei: neighbor[current]){
            if(distance.find(nei)!= distance.end()
               && distance[current]-1 == distance[nei] ){
                path.push_back(nei);
                DFS(nei, endWord, distance, neighbor, res, path);
                path.pop_back();
            }            
        }
    }
    
    // get neighbor function with 26 letters method
    vector<string> get_neighbor(string input, unordered_set<string> &dict){
        vector<string> result;
        
        for(int i=0; i< input.size(); i++){
            string temp = input;
            
            for(int j=0; j<26; j++){
                temp[i] = 'a'+ j;
                if(dict.find(temp)!=dict.end() && temp!=input){
                    result.push_back(temp);
                    // cout<< "get neighbor: " <<temp <<endl;
                }
            }
        }
        return result;
    }
};
