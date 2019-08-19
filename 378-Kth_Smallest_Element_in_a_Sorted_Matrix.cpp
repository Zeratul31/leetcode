class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==0)
            return -1;
        
        int n_size = matrix.size();
        int start = matrix[0][0];
        int end = matrix[n_size-1][n_size-1];
        
        while (start < end){ // if use start + 1 < end then need to judge again for each of them. so use start < end
            int mid = start + (end - start)/2;
            int cnt = find_lower_than_mid(matrix, mid);
            
            if(cnt < k) // hard part: cnt = k still need: end = mid
                start = mid + 1; // hard part: if no +1 then mid = start + (end - start)/2 = mid + 0.5 still mid. so need to use + 1
            else
                end = mid;
        }
        return start;
    }
    
    int find_lower_than_mid (vector<vector<int>>& matrix, int mid){
        int m_size = matrix.size();
        int i = m_size - 1, j = 0;
        int cnt = 0;
        
        while (i>=0 && j < m_size){
            
            if(matrix[i][j] <= mid){
                cnt = cnt + i + 1;
                j++;
            }else
                i--;
        }
        return cnt;
    }
};
