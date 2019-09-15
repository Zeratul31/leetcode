class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        
        int left =0;
        int right = s.size()-1;
        
        while(left<right){
            while(left<s.size() && !is_valid(s[left]))
                left++;
            
            if(left == s.size())    return true;
            
            while(right>=0 && !is_valid(s[right]))
                right--;
            
            if( transfer(s[left]) == transfer(s[right]) ){
                left++;
                right--;
            }else{
                break;
            }
        }
        return left>=right;
    }
    
private:
    char transfer(char &input){
        if(input>='A' && input<='Z'){
            input = input-'A'+'a';
        }
        return input;
    }
    
    bool is_valid(char input){
        if( (input>='a' && input<='z')
           || (input>='A' && input<='Z')
           || (input>='0' && input<='9')
           )
            return true;
        else
            return false;
    }
};
