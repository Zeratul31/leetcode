class Solution {
public: // method of DP / greedy
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int A[n];
        
        int end = nums[0]; // max index it can hit
        
        for(int i = 0; i < n; i++)
        {
            if(end < i)
                return false;
            
            end = max(end, i + nums[i]);
            
            if(end >= n - 1)
                return true; // stop in advance
        }
        return end >= n - 1;
    }
};
