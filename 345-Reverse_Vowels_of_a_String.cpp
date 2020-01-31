// method: two points
// TC: O(n), SC: O(10) vowel, n is length of string

class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() == 0)
            return s;
        
        int size = s.size();
        unordered_set <char> set;
        set.emplace('a');
        set.emplace('e');
        set.emplace('i');
        set.emplace('o');
        set.emplace('u');
        set.emplace('A');
        set.emplace('E');
        set.emplace('I');
        set.emplace('O');
        set.emplace('U');
        
        int left = 0;
        int right = size - 1;
        
        while(left < right){
            
            while(left < right && set.find(s[left]) == set.end() )
                left++;
            
            while(left < right && set.find(s[right]) == set.end() )
                right--;
            
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            // must continue to move two points!!
            left++;
            right--;
        }
        return s;
    }
};
