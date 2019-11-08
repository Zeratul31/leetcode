class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int sum;
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){ // fix largest and check two sum of previous left and right points
            int temp = target - nums[i];
            int left = 0;
            int right = i - 1;
            
            while(left < right){
                
                if(diff > abs(temp - nums[left] - nums[right]) )
                {
                    diff = abs(temp - nums[left] - nums[right]);
                    sum = nums[left] + nums[right] + nums[i];
                }
                
                if(temp - nums[left] - nums[right] > 0)
                {
                    left++;
                }
                else
                {
                    right--;                    
                }
                
            }
        }
        return sum;
    }
};
