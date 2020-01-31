// method: reverse and swap char OR use two points to traverse all array
// TC: O(n)


class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for(int i = 0; i < size/2; i++){
            swap(s[i], s[size - i - 1]);               
        }
    }
    
    void swap(char &left, char &right){
        char temp;
        temp = left;
        left = right;
        right = temp;
    }
};
