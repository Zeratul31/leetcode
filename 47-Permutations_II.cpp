class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        vector<bool> visited(nums.size(), false);// key point
        
        if(nums.size()==0)
            return res;
        sort(nums.begin(), nums.end()); // need sort
        helper(res, subset, nums, visited);
        return res;
    }
    
private:
    void helper(vector<vector<int>> &res, vector<int> &subset, vector<int>& nums, vector<bool> &visited){
        
        if(subset.size() == nums.size())
            res.push_back(subset);
        
        for(int i=0; i< nums.size(); i++){
            if(visited[i])
                continue;
            
            if(i>0 && (nums[i] == nums[i-1]) && !visited[i-1])//hard part
                continue;
            
            subset.push_back(nums[i]);
            visited[i] = true;
            
            helper(res, subset, nums, visited);
            
            subset.pop_back();
            visited[i] = false;
        }
    }
};
