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

//method 2: DFS + level limited:
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > res;
        unordered_set <string> set;
        for(auto item: wordList)
            set.emplace(item);
        set.emplace(beginWord);
        
        if(wordList.size()==0 || set.find(endWord)==set.end())  return res;
        
        unordered_map <string, vector<string> > neighbor;
        unordered_map<string, int> distance;
        wordList.push_back(beginWord);
        
        for(auto item: wordList){
            neighbor_get(item, neighbor, set);
            distance_get(item, endWord, distance);
        }
        
        int limit = 1;
        vector<string> path;
        path.push_back(beginWord); // do not forget
        
        while(res.empty() && (limit<wordList.size() )  ){
            dfs(limit, 1, beginWord, endWord, path, res, distance, neighbor);
            limit++;
        }
        return res;
    }
    
private:
    void dfs(int limit, int cur_level, string word, string endWord, vector<string> &path, vector<vector<string> > &res, unordered_map<string, int> &distance, unordered_map <string, vector<string> > &neighbor){
        if(cur_level==limit){
            if(word == endWord)
                res.push_back(path);
            return;
        }
        
        //if distance is larger than limit requirement then it cannot transfer within limit
        if(distance[word] + cur_level > limit)    return;
        
        for(auto item: neighbor[word]){
            path.push_back(item);
            dfs(limit, cur_level+1, item, endWord, path, res, distance, neighbor);
            path.pop_back();
        }
        
        // hard part: if res is empty, it means the minimum distance is not enough!!
        if(res.empty()){ // both works
            // distance[word] = max(distance[word], limit - (cur_level-1) +1);
            distance[word] = distance[word]+1 ;
        }
    }
    
    void neighbor_get(string input, unordered_map <string, vector<string> > &neighbor, unordered_set <string> &set){
        vector<string> temp;
        for(int i=0; i<input.size();i++){
            string str = input;
            for(int j=0; j<26; j++){
                str[i] = 'a'+j;
                if(str!=input && set.find(str)!=set.end()){
                    temp.push_back(str);
                }
            }
        }
        neighbor.emplace(input,temp);
    }
    
    void distance_get(string input, string endWord, unordered_map<string, int> &distance){
        int diff=0;
        for(int i=0; i<input.size();i++){
            if(input[i]!=endWord[i])
                diff++;
        }
        distance.emplace(input, diff);
    } // this is for minmum requirement of steps/levels we need
};
