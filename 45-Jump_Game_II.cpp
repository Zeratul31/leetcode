// version 1: Dynamic Programming
// 这个方法，复杂度是 O(n^2)，会超时，但是依然需要掌握。

class Solution {
public: // method of DP
    int jump(vector<int>& nums) {
        int step[nums.size()];
        
        step[0] = 0;
        
        for(int i = 1; i < nums.size(); i++)
            step[i] = INT_MAX;
        
        
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(step[j] != INT_MAX && nums[j] + j >= i) // key point!!
                    step[i] = min(step[i], step[j] + 1);
            }
        }
        return step[nums.size() - 1];
    }
};

// version 2: Greedy

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int i = 0, pre = 0, cur = 0, jumps = 0, start = 0;
        
        while(cur < nums.size() - 1) // becareful ! cur == nums.size()-1 it already hit the end !!
        {
            jumps++;
            pre = cur;
            
            for(i = start; i <= pre; i++)
            {
                cur = max(cur, nums[i] + i);
            }
            if(cur == pre)  return -1;
            
            start = pre + 1;
        }
        return jumps;
    }
};
