class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0; // slow points to non-zero right position, fast to sweep all vector
        
        while(fast < nums.size()){
            if(nums[fast] != 0){
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                slow++;
            }
            fast++;
        }
    }
};
