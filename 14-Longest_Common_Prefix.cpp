// method: 根据第一个字符串内容的顺序来遍历所有字符串的内容，出现不一样或者长度不够时就结束。
// hard part: i > strs[j].size() - 1 OR i >= strs[j].size()
// TC: O(n^2), SC: O(1) 


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 || strs[0].size() == 0)
            return "";
        
        string base = strs[0];
        
        for(int i = 0; i < base.size(); i++){
            for(int j = 0; j < strs.size(); j++){
                if(i > strs[j].size() - 1 || base[i] != strs[j][i]) // hard
                    return base.substr(0, i);
            }
        }
        return base;
    }
};
