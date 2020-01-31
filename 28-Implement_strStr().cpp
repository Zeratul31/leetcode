// method: traverse all the string
// TC: O(n*m)

// KMP method can hit TC: O(m+n)

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "" || haystack == needle)
            return 0;
        
        int n = haystack.size();
        int m = needle.size();
        
        if(m > n)
            return -1;
        
        for(int i = 0; i <= (n - m); i++){//careful about "<="
            if(haystack.substr(i, m) == needle)
                return i;
        }
        return -1;
    }
};
