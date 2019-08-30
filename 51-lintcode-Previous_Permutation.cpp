class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        int n = nums.size();
        int i,j;
        // carefull!! for boundary conditions at for loop !!
        for(i=n-1; i>0;i--){
            if(nums[i]<nums[i-1]){
                reverse(nums.begin() + i, nums.end());
                for(j=i;j<n;j++){ 
                    if(nums[i-1]>nums[j]){
                        swap(nums[i-1],nums[j]);
                        return nums;
                    }
                }
            }
        }
        
        reverse(nums.begin(), nums.end());
        return nums;
    }
};
