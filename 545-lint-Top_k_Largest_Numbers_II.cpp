bool cmp(const int& a, const int& b) // careful!
{
    return a > b;
}

class Solution {
public:
    
    priority_queue <int, vector<int>, greater<int> > pq; // min is top
    int kk;
    /*
     * @param k: An integer
     */Solution(int k) {
         kk = k;
     }
    
    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        if(pq.size() < kk)
        {
            pq.push(num);
        }
        else
        {
            if(num > pq.top())
            {
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    /*
     * @return: Top k element
     */
    vector<int> topk() {
        vector<int> res;
        int s = pq.size();
        for(int i = 0; i < s && i < kk; i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }
        
        for(auto item: res)
        {
            pq.push(item);
        }
        
        sort(res.begin(), res.end(), cmp); // careful
        // sort(res.begin(), res.end()); // also work
        // reverse(res.begin(), res.end());
        return res;
    }
};
