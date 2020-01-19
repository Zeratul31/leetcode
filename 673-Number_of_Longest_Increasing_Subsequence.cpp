//len[i] 表示以 nums[i] 为结尾的递推序列的长度. len[i] 不是 index i的LIS！！
//TC: O(n^2)
// similar to “300. Longest Increasing Subsequence”.

// 思路难点是：新建两个数组，对于每个index，一个记录LIS长度，一个记录LIS的个数
// 如果index j的LIS + 1 == index i的LIS，说明该index j可以和nums[i]组成和之前index i的LIS一样长的LIS，所以cnt结果可以叠加。如果len[j] + 1 > len[i]，说明有新的LIS出现，要把cnt更新一下

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        
        int len[nums.size()]; // len(i) is LIS length at index i
        int cnt[nums.size()]; // cnt(i) is LIS total count at index i
        int res = 0;
        int max_len = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++)
        {
            len[i] = 1;
            cnt[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(len[j] + 1 == len[i]) // LIS at j + nums[i] is same as previous len[i], so we can add it up
                    {
                        cnt[i] = cnt[i] + cnt[j];
                    }
                    else if(len[j] + 1 > len[i]) // LIS at j + nums[i] can create a new long LIS
                    {
                        len[i] = len[j] + 1; // need to update len[i] here!
                        cnt[i] = cnt[j];
                    }
                }
            }
            
            
            if(max_len == len[i])
                res = res + cnt[i]; //因为len[i] 表示以 nums[i] 为结尾的递推序列的长度，所以如果len[i] == max_len, 说明有新的满足maxlen的nums[i]出现，可以往结果里加
            
            else if(max_len < len[i])
            {
                max_len = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
};
