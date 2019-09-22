class Solution { // use two points method
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.size()==0) return 0;
        
        int res=0;
        int i=0,j=0; // i is the start point and j is end point
        unordered_map<char, int> map; // record whether this char has exist
        
        for(i=0; i<s.size(); i++){
            while(j<s.size() && map[s[j]]==0){ // only move j if not exist in map
                map[s[j]]=1;
                res = max(res, j-i+1);
                j++;
            }
            
            map[s[i]]=0; // move start point and need to clean that char 
        }
        return res;
    }
};
