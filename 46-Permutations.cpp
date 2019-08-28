class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        
        if(nums.size()==0)
            return res;
        
        unordered_set<int> hash_set;
        helper(res, subset, nums, hash_set);
        return res;
    }
    
private:
    void helper(vector<vector<int>> &res, vector<int> &subset, vector<int>& nums, unordered_set<int> &hash_set){
        
        if(subset.size() == nums.size())
            res.push_back(subset);
        
        for(int i=0; i< nums.size(); i++){
            if(hash_set.find(nums[i])!= hash_set.end())
                continue;
            
            hash_set.emplace(nums[i]);
            subset.push_back(nums[i]);
            helper(res, subset, nums, hash_set);
            subset.pop_back(); // carefull
            hash_set.erase(nums[i]); //carefull
        }
    }
};
