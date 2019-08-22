
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        //00-22
        //01-23
        //02-13
        //03-03
        //10-21
        int m = matrix.size(); // 3
        int n = matrix[0].size(); // 4
        
        for(int i=0; i<m; i++){
            for(int j=0;j<n;j++){
                
                if((i+1<m) && (j+1<n)&& (matrix[i][j] != matrix[i+1][j+1]) )
                    return false;
                else
                    continue;
            }
        }
        return true;
    }
};
