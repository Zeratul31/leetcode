
300. Longest Increasing Subsequence

// method 1:
// time complexity: O(n^2)
// f(i) 是 前i 数组的LIS值， 这个方法是从i=0遍历到结尾


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        
        int f[nums.size()];
        int max_value = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            f[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i]) // key point: only find nums[j] < nums[i], f[i] can be >= f[j]+1, be careful this is f[j] not nums[j]
                {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            if(f[i] > max_value)
                max_value = f[i];
        }
        return max_value;
    }
};

// method 2: 遍历一遍+二分法
// TC = O(nlogn)
// 在格外数组中用二分法查找，如果新来的数比前面的数都大，就加在末尾，如果不是，就把前面数字中第一个比它大的替换掉：
// 比如格外数组是[2,3,7] ，next is 12，数组变成[2,3,7,12]. if next is 4, 数组变成 [2,3,4]，这样如果next next是6，就可以生成[2,3,4,6 ]

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)    return nums.size();
        
        vector<int> extra;
        extra.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++)
        {
            int e_size = extra.size();
            if(nums[i] > extra[e_size - 1])
            {
                extra.push_back(nums[i]);
            }
            else if(nums[i] < extra[e_size - 1])
            {
                int index = binary_search(extra, nums[i]);
                if(index == -1)
                    continue;
                else
                    extra[index] = nums[i];
            }
        }
        return extra.size();
    }
    
    
    int binary_search(vector<int> &extra, int target)
    {
        int index;
        int start = 0;
        int end = extra.size() - 1;
        
        while(start < end - 1)
        {
            int mid = start + (end - start)/2;
            
            if(extra[mid] == target)
                return -1;
            else if(extra[mid] > target)
                end = mid;
            else
                start = mid;
        }
        
        if(extra[start] > target)
            return start;
        else if(extra[start] < target && extra[end] > target)
            return end;
        else
            return -1;
    }
};
