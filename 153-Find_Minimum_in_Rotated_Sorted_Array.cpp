class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start + 1 < end){
            int mid = start + (end - start)/2;
            
            if(in_last_half(nums, mid))
                end = mid;
            else
                start = mid;
        }
        
        if(nums[start] < nums[end])
            return nums[start];
        else
            return nums[end];
        
    }
    
    bool in_last_half(vector<int>& nums, int index){
        if(nums[index] <= nums[nums.size() - 1])
            return true;
        else
            return false;
    }
    
    
};
