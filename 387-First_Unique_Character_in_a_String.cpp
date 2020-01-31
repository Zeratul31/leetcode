
// method: use hash map to store all char and then check char which shows one time
// TC: O(n), SC: O(n)

class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0)
            return -1;
        
        unordered_map<char, int> map;
        
        for(auto item: s){
            if(map.find(item) != map.end()){
                map[item]++;
            }
            else{
                map.emplace(item, 1);
            }
        }
        
        for(int i = 0; i < s.size(); i++){
            if(map[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
