class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 2)
            return -1;
        if(nums.size() == 1)
            return nums[0];
        
        int start = 0;
        int end = nums.size()-1;
        
        while(start + 1 < end){
            int mid = start + (end -start)/2;
            if(nums[mid]!= nums[mid-1] && nums[mid]!= nums[mid+1])
                return nums[mid];
            
            if(single_left(nums, mid))
                start = mid;
            else
                end = mid;
        }
        
        if(start == 0 ){
            return nums[0];
        }else{
            if(nums[start] == nums[start-1])
                return nums[end];
            else
                return nums[start];
        }
        
    }
    
    bool single_left(vector<int>& nums, int index){
        
        if(index%2 == 0){
            if(nums[index] == nums[index+1])
                return true;
            else
                return false;
        }else{
            if(nums[index] == nums[index-1])
                return true;
            else
                return false;
        }
    }
    
};
