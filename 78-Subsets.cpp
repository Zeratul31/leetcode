class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // DFS and result in this order.
        // this question does not has duplicate numbers, so no need to sort!
        // []
        // [1]
        // [1,2]
        // [1,2,3]
        // [1,3]
        // [2]
        // [2,3]
        // [3]
        
        vector<vector<int>> res;
        vector<int> temp_set;
        helper(res, temp_set, 0, nums);
        return res;
    }
    
private:
    void helper(vector<vector<int>> &res, vector<int> &temp_set, int start_idx,vector<int>& nums){
        res.push_back(temp_set);
        for(int i = start_idx; i< nums.size(); i++){
            temp_set.push_back(nums[i]);
            helper(res, temp_set, i+1, nums); // hard part "i+1"
            // temp_set.erase(temp_set.begin()+temp_set.size()-1);
            temp_set.pop_back();
        }
    }
};
