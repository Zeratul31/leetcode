class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0)  return true;
        if(t.size()==0)  return false;
        
        int i=0, j=0;
        while(i<s.size() && j<t.size()){
            if(s[i] == t[j] ){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return (i==s.size());
    }
};
