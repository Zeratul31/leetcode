// greedy + dp
// 先对于w 排序，之后找longest increasing sequence，可以用O(n^2)遍历或者O(nlogn)二分
// 举例：[[4,5],[4,6],[6,7],[2,3],[1,1]]
// 排序是[1,1], [2,3], [4,5], [4,6],[6,7] 但是[4,5]不能套娃 [4,6]
// 所以把顺序变成：[1,1], [2,3], [4,6], [4,5], [6,7]
// 这样在排序第二个变量h的时候[4,6]和 [4,5]就不会累加成一个LIS

// bool cmp(const pair<int,int>&x, const pair<int, int>&y) {
//     return x.first != y.first ? x.first < y.first : x.second > y.second;
// }

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0 || envelopes.size() == 1)  return envelopes.size();
        
        // sort(envelopes.begin(), envelopes.end());//wrong, we need to sort second too!!
        sort(envelopes.begin(), envelopes.end(), cmp );
        vector<int> LIS;
        LIS.push_back(envelopes[0][1]);
        
        for(int i = 1; i < envelopes.size(); i++)
        {
            int LIS_size = LIS.size();
            if(envelopes[i][1] > LIS[LIS_size - 1])
            {
                LIS.push_back(envelopes[i][1]);
            }
            else if(envelopes[i][1] < LIS[LIS_size - 1])
            {
                int index = binary_search(LIS, envelopes[i][1]);
                if(index == -1) // find same value item and no need to exchange
                    continue;
                else
                    LIS[index] = envelopes[i][1];
            }
        }
        return LIS.size();
    }
    
    // static bool cmp(const vector<vector<int>>&x, const vector<vector<int>>&y)// input format must match!!
    static bool cmp( vector<int> a,  vector<int> b)// input format must match!!
    {
        if(a[0] == b[0])
            return a[1] > b[1]; // 很巧妙，因为如果w一样就不能套娃,所以对于w一样的情况，h就反着排序
        else
            return a[0] < b[0];
    }
    
    int binary_search(vector<int>& LIS, int target)
    {
        int start = 0;
        int end = LIS.size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if(LIS[mid] == target)
                return -1;
            else if(LIS[mid] > target)
                end = mid;
            else
                start = mid;
        }
        
        if(target < LIS[start])
            return start;
        else if(target > LIS[start] && target < LIS[end])
            return end;
        else
            return -1;
    }
    
};
