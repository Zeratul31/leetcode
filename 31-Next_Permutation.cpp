class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n_size = nums.size();
        
        for(int i=n_size-1; i>0; i--){
            if(nums[i-1]<nums[i]){ // try to find first non-increasing number
                int j;
                for(j=n_size-1; j>=i; --j){
                    if(nums[i-1]<nums[j]) // because left part is all increasing order
                        break;
                }        
                // cout<< "j is: "<< to_string(j) << endl;
                swap(nums[i-1], nums[j]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
