
class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // similar to two sum
        int res = 0;
        
        if(S.size() < 3)    return res;
        
        sort(S.begin(), S.end());
        
        for(int i = 0; i < S.size(); i++){
            int left = 0;
            int right = i - 1;
            
            while(left < right){
                if(S[left] + S[right] > S[i]) // two short edge sum is larger than longest edge
                {
                    res = res + right - left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return res;
    }
};
