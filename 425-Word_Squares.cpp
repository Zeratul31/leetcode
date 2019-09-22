
class Solution {
public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        vector<vector<string>> res;
        if(words.size()==0 ||words[0].size()==0)    return res;
        
        unordered_map<string, vector<string> > map; // <prefix, words>
        vector<string> path;
        
        init_prefix(words, map);
        dfs(0, words[0].size(), res, map, path);
        return res;
    }
    
private:
    void init_prefix(vector<string> &words, unordered_map<string, vector<string> > &map){
        vector<string> temp;
        map.emplace("",temp); // need to have an empty prefix
        
        for(auto each_word: words){
            map[""].push_back(each_word);
            
            string prefix;
            for(auto letter: each_word){// "a"->area, "ar"->area, ... "area"->area
                prefix += letter;
                vector<string> t;
                map.emplace(prefix,t);
                map[prefix].push_back(each_word);
            }
        }
    }
    
    void dfs(int x, int l, vector<vector<string>> &res, unordered_map<string, vector<string> > &map, vector<string> &path){
        if(x==l){
            res.push_back(path);
            return;
        }
        
        string prefix="";
        for(auto item: path){
            prefix += item[x]; // e.g: x=2, prefix = le
        }
        
        for(auto item: map[prefix]){
            if(!check_prefix(x,l,item, map, path)) // hard part !
                continue;
            
            path.push_back(item);
            dfs(x+1, l, res, map, path);
            path.pop_back();
        }
    }
    
    bool check_prefix(int x, int l, string input, unordered_map<string, vector<string> > &map, vector<string> &path){
        //e.g: if we put area, we need to check word with prefix le and la exist
        
        for(int i=x+1; i<l; i++){
            string prefix;
            for(auto item: path){
                prefix += item[i]; // l l
            }
            prefix += input[i];// hard part: le la
            if(map.find(prefix)==map.end())
                return false;
        }
        return true;
    }
};
