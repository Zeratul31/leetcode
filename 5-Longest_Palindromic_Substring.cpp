class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1)
            return s;
        
        int length = s.size();
        int len = 0;
        int start = 0;
        
        for(int i = 0; i < length; i ++){
            int temp_len = 0;
            int temp_start;
            find_pdc_start_len(s, i, i, temp_start, temp_len); // for odd case
            
            if(temp_len > len){
                len = temp_len;
                start = temp_start;
            }
            
            find_pdc_start_len(s, i, i + 1, temp_start, temp_len); // for even case
            
            if(temp_len > len){
                len = temp_len;
                start = temp_start;
            }
        }
        
        string res;
        res = s.substr(start, len);
        return res;
    }
    
private:
    void find_pdc_start_len (string &s, int start, int end, int &start_index, int &length){
        length = 0;
        while (start >= 0 && end < s.size()){
            if(s[start] != s[end])
                break;
            
            if(start == end)
                length += 1;
            else
                length += 2;
            
            start--;
            end++;
        }
        start_index = start + 1; // careful for + 1
    }
    
};
