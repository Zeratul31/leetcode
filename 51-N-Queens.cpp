class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n==0 || n==2)
            return res;
        
        // vector<string> queen(n, string(n,"."));
        vector<string> queen;
        
        helper(res, queen, n);
        return res;
    }
    
private:
    void helper(vector<vector<string>> &res, vector<string> &queen, int n){
        if(queen.size()==n)
            res.push_back(queen);
        
        for(int i=0; i<n; i++){
            
            if(isValid(queen, i, n)) // check Q is valid at place i
                queen.push_back(draw_res(i,n)); // put Q at place i
            else
                continue;
            
            helper(res, queen, n);
            
            queen.pop_back();
        }
    }
    
    string draw_res(int cur_col, int n){
        string result(n,'.');
        result[cur_col] = 'Q';
        return result;
    }
    
    bool isValid(vector<string> &queen, int cur_col, int n){
        int row = queen.size();
        for(int i=0; i<row; i++){ // row
            for(int j=0; j<n; j++){
                if(queen[i][j]=='Q'){ // check queen valid
                    if(j==cur_col || abs(i-row) == abs(j-cur_col)){ // hard part
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
