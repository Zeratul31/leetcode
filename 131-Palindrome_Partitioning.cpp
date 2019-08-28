class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> substring;
        
        if(s=="")
            return res;
        
        helper(s, res, substring, 0);
        return res;
    }
    
    
private:
    void helper(string s, vector<vector<string>> &res, vector<string>& substring, int idx){
        if(idx == s.size()) // hard part
            res.push_back(substring);
        
        for(int i=idx; i< s.size(); i++){
            string temp = s.substr(idx, i-idx+1); // hard part
            
            if(!Palindrome(temp))
                continue;
            else
                substring.push_back(temp);
            
            helper(s, res, substring, i+1); // hard part
            substring.pop_back();
        }
    }
    
    bool Palindrome(string input){
        for (int i=0, j=input.size()-1; i<j; i++, j--){
            if(input[i]!=input[j])
                return false;
        }
        return true;
    }
};
