class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size()==0) return true;
        
        int left = 0;
        int right = s.size()-1;
        
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }else
            {
                return (isValid(s, left+1, right) || isValid(s, left, right-1));
            }
        }
        return (left>=right);
    }
    
    bool isValid (string &s, int left, int right){
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }else{
                break;
            }            
        }
        return (left>=right);
    }
};
