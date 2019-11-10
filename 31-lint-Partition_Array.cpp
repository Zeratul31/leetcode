
class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        if(nums.size() == 0)    return 0;
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right){
            while(left < right && nums[left] < k)
                left++;
            
            while(left < right && nums[right] >= k)
                right--;
            
            if(left < right)
            {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
        }
        
        if(nums[left] < k) // case for all item smaller than k
            return left + 1;
        else
            return left;
    }
};
