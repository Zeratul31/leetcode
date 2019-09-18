class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)  return "";
        // if(strs.size()==1)  return strs[0];
        
        for(int j=0; j<strs[0].size();j++){
            for(int i=0; i<strs.size();i++){
                if(j>=strs[i].size() || strs[0][j]!=strs[i][j])
                    return strs[0].substr(0,j);
            }
        }
        return strs[0]; 
    }
};
