class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        long long res = 0;
        if(A.size()==0 || A.size() == 1)
            return res;
        
        res = merge_sort(A, 0, A.size()-1);
        return res;
    }
    
private:
    
    long long merge_sort(vector<int> &A, int start, int end){
        long long sum = 0;
        if(start == end)    return sum;
        
        int mid = start + (end - start)/2;
        
        sum = sum + merge_sort(A, start, mid);
        sum = sum + merge_sort(A, mid+1, end);
        sum = sum + merge(A, start, mid, end);
        
        return sum;
    }
    
    long long merge(vector<int> &A, int start, int mid, int end){
        long long sum = 0;
        
        vector<int> temp;
        int left = start;
        int right = mid+1;
        
        while(left<=mid && right<=end){
            if(A[left]<=A[right])
                temp.push_back(A[left++]);
            else{
                temp.push_back(A[right++]);
                sum = sum + mid-left +1 ;// hard part
                // cout<< "sum is " << to_string(sum) << endl;
            }
        }
        while(left<=mid)    temp.push_back(A[left++]);
        while(right<=end)    temp.push_back(A[right++]);
        
        int j=0;
        for(int i=start; i<=end;i++){ // carefull for i<=end 
            A[i] = temp[j];
            j++;
        }        
        return sum;    
    }
};
