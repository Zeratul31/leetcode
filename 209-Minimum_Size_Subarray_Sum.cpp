// method of binary search: O(nlogn)
// method of two points: O(n)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if(nums.size() == 0)    return 0;
        
        int left = 0;
        int right = 0;
        int sum = 0;
        int res = INT_MAX;
        
        for(right = 0; right < nums.size(); right++)// method of sum is hard point!!
        {
            sum = sum + nums[right];
            
            while(left <= right && sum >= s) // both works
                // while(sum >= s)
            {
                res = min(res, right - left + 1);
                sum = sum - nums[left];
                left++;
            }
        }
        
        if(res == INT_MAX)
            return 0;
        else
            return res;
    }
};
