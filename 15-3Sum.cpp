class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3)
            return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++){
            
            if(i > 0 && nums[i] == nums[i - 1]) // skip for duplicate case
                continue;
            
            int target = - nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            
            vector<vector<int>> temp; // [0, 1] [-1, 2]
            temp = two_sum(nums, start, end, target);
            
            if(temp.size() != 0){
                for(auto item: temp){
                    item.push_back(nums[i]);
                    res.push_back(item);
                }
            }
            
        }
        return res;
    }
private:
    vector<vector<int>> two_sum(vector<int>& nums, int start, int end, int target)
    { // find unique two pairs for target
        vector<vector<int>> res;
        
        while(start < end){
            if(nums[start] + nums[end] == target)
            {
                vector<int> temp;
                temp.push_back(nums[start]);
                temp.push_back(nums[end]);
                res.push_back(temp);
                start++;
                end--;
                
                // be carefull for duplicate case. need to remove them
                while(start < end && nums[start] == nums[start - 1])
                    start++;
                
                while(start < end && nums[end] == nums[end + 1])
                    end--;
            }
            else if(nums[start] + nums[end] < target)
                start++;
            else
                end--;
            
        }
        
        return res;
    }
};
