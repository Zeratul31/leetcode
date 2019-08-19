
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) // check first
            return -1;
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start + 1 < end){
            int mid = start + (end - start)/2;
            
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                start = mid;
            }else{
                end = mid;
            }
        }
        
        if(nums[start] == target){
            return start;
        }else if(nums[end] == target){
            return end;
        }else{
            return -1;
        }
    }
};
