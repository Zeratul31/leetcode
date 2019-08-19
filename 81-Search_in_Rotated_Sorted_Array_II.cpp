class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if(nums.size() == 0)
            return false;
        
        int start = 0;
        int end = nums.size()-1;
        
        while (start + 1< end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] < nums[end]){ // this means right part is sorted
                if(target >nums[mid] && target <= nums[end])
                    start = mid;
                else
                    end = mid;
            }
            else if(nums[mid] > nums[end]){ // this means left part is sorted)
                if(target < nums[mid] && target >= nums[start])
                    end = mid;
                else
                    start = mid;
            }else{ // cannot judge which part is sorted and can only remove last one
                end -- ; // so time complexity can be up to O(n)
            }
        }
        
        if(nums[start] == target || nums[end] == target)
            return true;
        else
            return false;
    }
};
