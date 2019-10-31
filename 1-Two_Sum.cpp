class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // method of hash set
        unordered_map<int, int> map;
        vector<int> res;
        
        if(nums.size() == 0 || nums.size() == 1)    return res;
        
        for(int i = 0; i < nums.size(); i++){
            map.emplace(nums[i], i);
        }
        
        for(int i = 0; i< nums.size(); i++){
            if(map.find(target - nums[i]) != map.end() && map[target - nums[i]] != i){
                res.push_back(i);
                res.push_back(map[target - nums[i]]);
                break;
            }
        }
        
        return res;
    }
};


