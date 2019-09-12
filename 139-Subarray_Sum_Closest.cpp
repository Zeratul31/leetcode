class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        vector<pair<int, int> > prefix; // sum and index
        prefix.push_back(make_pair(0, -1));
        
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum = sum+nums[i];
            prefix.push_back(make_pair(sum, i));
        }
        
        // prefix[j] - prefix[i] = sum of sub [ from i+1 to ... j]
        sort(prefix.begin(), prefix.end());
        int min_sum = INT_MAX;
        int a, b;
        for(int i=1; i< prefix.size(); i++){
            if ( (prefix[i].first - prefix[i-1].first) <=min_sum){//<= the = is for conner case
                min_sum = (prefix[i].first - prefix[i-1].first);
                a = prefix[i-1].second;
                b = prefix[i].second;
            }
        }
        
        vector<int> res;
        res.push_back(1+min(a,b));
        res.push_back(max(a,b));
        
        return res;
    }
};
