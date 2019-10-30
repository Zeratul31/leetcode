
class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // 三步翻转法
        int length = nums.size();
        if(length == 0 || length == 1) return;
        
        int offset = 0;
        for(int i = 0; i < length - 1; i ++){
            if(nums[i] > nums[i + 1])
                offset = i + 1;
        }
        
        reverse(nums, 0, offset - 1);
        reverse(nums, offset, length - 1);
        reverse(nums, 0, length - 1);
    }
private:
    void reverse(vector<int> &input, int start, int end){
        while(start < end){
            int temp = input[end];
            input[end] = input[start];
            input[start] = temp;
            start++;
            end--;
        }
    }
};
