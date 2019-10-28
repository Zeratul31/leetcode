
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char, int> map;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(map.find(s[i]) != map.end() )
                map[s[i]]++;
            else
                map.emplace(s[i], 1);
        }
        
        bool flag = true; // flag for odd letter
        int res = 0;
        
        for(auto item: map){
            if(item.second % 2 == 0)
                res = res + item.second;
            else{
                res = res + item.second - 1;
                
                if(flag)
                    res++;
                
                flag = false;
                
            }
            
        }
        
        return res;
    }
};
