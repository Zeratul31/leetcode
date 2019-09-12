class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int minTotalDistance(vector<vector<int>> &grid) {
        vector<int> x,y;
        if(grid.size()==0 || grid[0].size()==0)
            return 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j< grid[0].size(); j++){
                if(grid[i][j]==1){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        
        return dist(x) + dist(y);
    }
    
private:
    int dist(vector<int> &input){
        int n = input.size();
        if(n==0)    return -1;
        
        int res=0;
        sort(input.begin(), input.end());
        int median = (input[n/2] + input[(n-1)/2] )/2; // hard part to get median
        
        for(auto i: input){
            res = res + abs(median - i);
        }
        return res;
    }
};
