class Solution {
public:
    int nthUglyNumber(int n) {  // O(n) use scan method
        
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> res;
        res.push_back(1); // always start with 1
        
        while(res.size() < n)
        {
            int res2 = res[p2] * 2;
            int res3 = res[p3] * 3;
            int res5 = res[p5] * 5;
            int last = min(res2, min(res3, res5));
            
            if(last == res2)    p2++;
            if(last == res3)    p3++;
            if(last == res5)    p5++;
            
            res.push_back(last);
        }
        return res[n-1];
    }
};

class Solution {
public:
    int nthUglyNumber(int n) { // use hesh + heap: O(nlogn)
        unordered_set <long> set;
        priority_queue<long, vector<long>, greater<long> > pq; // top is min
        
        pq.push(1);
        set.emplace(1);
        
        vector<long> num;
        num.push_back(2);
        num.push_back(3);
        num.push_back(5);
        
        for(int i = 1; i < n; i++)
        {
            long temp = pq.top();
            pq.pop();
            
            for(int j = 0; j < 3; j++)
            {
                if(set.find(temp * num[j]) == set.end())
                {
                    pq.push(temp * num[j]);
                    set.emplace(temp * num[j]);
                }
            }
        }
        return pq.top();
    }
};
