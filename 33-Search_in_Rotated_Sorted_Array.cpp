class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        
        int start = 0;
        int end = nums.size()-1;
        
        while(start + 1 < end){
            int mid = start + (end - start)/2;
            
            if(nums[mid] == target)
                return mid;
            
            if(in_first_half(nums, mid) ){
                if( target >= nums[0] && target < nums[mid])
                    end = mid;
                else
                    start = mid;
            }
            else{
                if( target > nums[mid] && target <= nums[nums.size()-1])
                    start = mid;
                else
                    end = mid;
            }
        }
        
        if(nums[start] == target)
            return start;
        else if(nums[end] == target)
            return end;
        else
            return -1;
        
    }
    
    
    bool in_first_half(vector<int>& nums, int input){
        if (nums[input] >= nums[0])
            return true;
        else
            return false;
    }
};
