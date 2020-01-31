
// 方法是dp
// 首先要排序
// LDS[i]代表的是以nums[i]为最大元素的LDS是多长

// TC = O(n^2), SC = O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1)
            return nums;
        
        vector<int> res;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());  // need to sort first
        
        vector<int> parent(n, 0);       // record previous LDS index j for current index i
        vector<int> LDS(n, 0);          // record index i LDS length
        int max_length = 0;             // max LDS length
        int index;                      // max index in LDS vector
        
        for(int i = 0; i < n; i++)
        {
            LDS[i] = 1;
            parent[i] = -1;
            
            for(int j = 0; j < i; j++)
            {
                if( nums[i] % nums[j] == 0 && LDS[i] < LDS[j] + 1) //i之前的都已经满足LDS了，所以只要检查i和j能不能整除就行
                {
                    LDS[i] = LDS[j] + 1;
                    parent[i] = j;  // update parent index !
                }
            }
            
            if(max_length < LDS[i])
            {
                max_length = LDS[i];
                index = i;
            }
            
        }
        
        for(int i = 0; i < max_length; i++)
        {
            res.push_back(nums[index]);     // save LDS element in a reverse order
            index = parent[index];          // update index by parent vector
        }
        return res;
    }
};
