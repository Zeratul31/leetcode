
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<vector<int>> res;
        if(length < 4)  return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < length - 3; i++){
            if( i > 0 && (nums[i] == nums[i - 1]) )
                continue;
            
            for(int j = i + 1; j < length - 2; j++){
                if( j > i + 1 && (nums[j] == nums[j - 1]) )
                    continue;
                
                vector<vector<int>> temp;
                int left = j + 1;
                int right = length - 1;
                
                temp = twosum(nums, target - nums[i] - nums[j], left, right);
                
                if(temp.size() != 0){
                    for(auto item: temp){
                        item.push_back(nums[i]);
                        item.push_back(nums[j]);
                        res.push_back(item);
                    }
                }
            }
        }
        return res;
    }
    
private:
    vector<vector<int>> twosum(vector<int>& nums, int target, int left, int right)
    {
        vector<vector<int>> res;
        
        while(left < right){
            if(nums[left] + nums[right] == target)
            {
                vector<int> temp;
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                res.push_back(temp);
                left++;
                right--;
                
                while(left < right && nums[left] == nums[left - 1]) //careful for left-1
                    left++;
                
                while(left < right && nums[right] == nums[right + 1])//careful for right+1
                    right--;
                
            }
            else if(nums[left] + nums[right] > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        
        return res;
    }
};
