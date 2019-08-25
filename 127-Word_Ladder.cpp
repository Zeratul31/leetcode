// improve to search for 26 words:
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //bfs traverse its neighbor and find its length
        
        // check for corner case
        bool end_word_exist = false;
        for(auto word: wordList){
            if(endWord==word)
                end_word_exist = true;
        }
        if(!end_word_exist) return 0;
        
        //main part
        int length = 0;
        queue<string> queue; // to save each level
        unordered_set<string> word_set;
        
        for(auto temp: wordList)
            word_set.emplace(temp);
        
        queue.push(beginWord);
        
        while(!queue.empty()){
            int q_size = queue.size();
            length++;
            
            for(int i=0; i<q_size; i++){
                string temp = queue.front();
                queue.pop();
                
                // traverse for 26 letters is key point to reduce time complexity
                for(int i=0; i< temp.size(); i++){
                    for(int j=0; j<26; j++){
                        string new_word = temp;
                        new_word[i] = 'a' + j;
                        
                        if(new_word!= temp && word_set.find(new_word)!=word_set.end()){
                            word_set.erase(new_word);
                            queue.push(new_word);
                            if(new_word == endWord)
                                return (length+1);
                        }
                    }
                }
            }
        }
        return 0;
    }
};


// time complex is bad
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //bfs traverse its neighbor and find its length
        
        // check for corner case
        bool end_word_exist = false;
        for(auto word: wordList){
            if(endWord==word)
                end_word_exist = true;
        }
        if(!end_word_exist) return 0;
        
        //main part
        int length = 0;
        queue<string> queue; // to save each level
        unordered_set<string> neigbor_set; //to check neighbor
        unordered_set<string> word_set;
        
        for(auto temp: wordList)
            word_set.emplace(temp);
        
        queue.push(beginWord);
        neigbor_set.emplace(beginWord);
        
        while(!queue.empty()){
            int q_size = queue.size();
            length++;
            
            for(int i=0; i<q_size; i++){
                string temp = queue.front();
                queue.pop();
                
                if(isNeighbor(temp, endWord))
                    return (length+1);
                
                for(auto nb: neighbor_word(temp, word_set)){// for temp's neighbor
                    if(neigbor_set.find(nb)==neigbor_set.end()){
                        neigbor_set.emplace(nb);
                        queue.push(nb);
                        if(word_set.find(nb)!=word_set.end()) // to speed up a little bit!
                            word_set.erase(nb);
                    }
                }
            }
        }
        return 0;
    }
    
private:
    bool isNeighbor (string word, string input){ // function to check neighbor
        if(word.size()!=input.size())
            return false;
        
        int sum=0;
        for(int i=0; i< word.size();i++){
            if(word[i]==input[i])
                sum++;
        }
        if(sum==word.size()-1)
            return true;
        else
            return false;
    }
    
    vector<string> neighbor_word(string input, unordered_set<string>& word_set){
        vector<string> res;
        
        for(auto i: word_set){
            if(isNeighbor(input, i))
                res.push_back(i);
        }
        return res;
    }
};
