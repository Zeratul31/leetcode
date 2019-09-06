
class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> result;
        if(A.size()==0 || B.size()==0)
            return result;
        
        result.resize(A.size() + B.size());
        
        int i=0, j=0, k=0;
        
        while(i<A.size() && j<B.size())
        {
            if(A[i]<=B[j])
                result[k++]=A[i++];
            else
                result[k++]=B[j++];
        }
        
        while(i<A.size()){
            result[k++] = A[i++];
        }
        while(j<B.size()){
            result[k++] = B[j++];
        }
        return result;
    }
};
