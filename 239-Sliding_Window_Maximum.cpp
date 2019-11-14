class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue < pair<int, int> > pq; // nums[i], i. default max is top
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++)
        {
            while(pq.size() != 0 && pq.top().second <= i - k) // hard part
                pq.pop(); // remove max num if max num is not within branket 
            
            pq.push({nums[i], i});
            
            if(i >= k - 1)
                res.push_back(pq.top().first);                
        }
        return res;
    }
};
