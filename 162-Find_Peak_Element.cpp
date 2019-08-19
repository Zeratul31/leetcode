class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() -1;
        
        
        while(start + 1 < end){
            int mid = start + (end - start)/2;
            if( (nums[mid] > nums[mid - 1]) &&  (nums[mid] > nums[mid + 1]) )
                return mid;
            
            if(in_raising_edge(nums, mid))
                start = mid;
            else
                end = mid;
        }
        
        if(nums[start] > nums[end])
            return start;
        else
            return end;
    }
    
    
    bool in_raising_edge(vector<int>& nums, int index){
        if(  (nums[index]> nums[index-1]) && (nums[index]< nums[index+1])  )
            return true;
        else
            return false;
    }
};
