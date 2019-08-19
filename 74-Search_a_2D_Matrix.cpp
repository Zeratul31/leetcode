class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        if(matrix[0].size() == 0)
            return false;
        
        int m_size = matrix.size();
        int n_size = matrix[0].size();
        int start = 0;
        int end = m_size*n_size -1;
        
        while(start + 1< end){
            int mid = start + (end - start)/2;
            if(value_in_matrix(matrix,mid) == target)
                return true;
            else if(value_in_matrix(matrix,mid) > target)
                end = mid;
            else
                start = mid;
        }
        
        if(value_in_matrix(matrix,start) == target || value_in_matrix(matrix,end) == target)
            return true;
        else
            return false;
    }
    
    int value_in_matrix(vector<vector<int>>& matrix, int index)
    {
        int m_size = matrix.size();
        int n_size = matrix[0].size();
        
        return matrix[index/n_size][index%n_size];
    }
    
};
