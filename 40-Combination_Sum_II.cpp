class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        
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
            if(i>start_idx && candidates[i]==candidates[i-1]) // hard part
                continue;
            
            subset.push_back(candidates[i]);
            helper(res, subset, candidates, remain_sum-candidates[i], i+1);// no duplicate candidate but can be same value for different candidates
            subset.pop_back();
        }
    }
};

