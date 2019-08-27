class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        // sort(candidates.begin(), candidates.end());
        
        helper(res, subset, candidates, target, 0);
        return res;
    }
    
private:
    void helper(vector<vector<int>> &res, vector<int> &subset, vector<int>& candidates, int remain_sum, int start_idx){
        
        if(remain_sum==0){
            res.push_back(subset);
            return;
        }
        if(remain_sum<0)
            return;
        
        for(int i=start_idx; i< candidates.size(); i++){
            subset.push_back(candidates[i]);
            helper(res, subset, candidates, remain_sum-candidates[i], i);
            subset.pop_back(); // carefull
        }
    }
};
