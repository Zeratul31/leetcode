
// method: reverse k at every 2k string and carefull for end part
// TC: O(n)

class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.size() == 0)
            return s;
        
        for(int i = 0; i < s.size(); i += 2*k){ // i = i + 2*k
            reverse(s, i, k);
        }
        return s;
    }
    
    void reverse(string &s, int i, int k){
        int left = i;
        int right;
        
        if(i + k > s.size()){
            right = s.size() - 1;
        }
        else{
            right = i + k - 1;
        }
        
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};
