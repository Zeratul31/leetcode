class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // DFS and result in this order.
        // this question has duplicate numbers, so need to sort!
        // []
        // [1]
        // [1,2]
        // [1,2,2]
        // [2]
        // [2,2]
        
        vector<vector<int>> res;
        vector<int> temp_set;
        sort(nums.begin(), nums.end()); // sort first
        helper(res, temp_set, 0, nums);
        return res;
    }
    
private:
    void helper(vector<vector<int>> &res, vector<int> &temp_set, int start_idx,vector<int>& nums){
        
        res.push_back(temp_set);
        
        for(int i = start_idx; i< nums.size(); i++){
            
            if( i>start_idx && nums[i] == nums[i-1]) // remove duplicate part
                continue;
            
            temp_set.push_back(nums[i]);
            helper(res, temp_set, i+1, nums); // hard part "i+1"
            temp_set.pop_back();
        }
        return;
    }
    
};
