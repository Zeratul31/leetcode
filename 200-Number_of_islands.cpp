class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0 || grid[0].size() == 0)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    BFS_fill(grid,i,j);
                    island++;
                }
            }
        }
        return island;
    }
    
private:
    // struct coordinate
    struct coordinate{
        int x; // row
        int y; // column
    };
    
    // bfs to flood fill adjacent points
    void BFS_fill(vector<vector<char>>& grid, int row, int column){
        int xx[4] = {-1,1,0,0};
        int yy[4] = {0,0,-1,1};
        queue<coordinate> queue;
        coordinate input;
        input.x=row;
        input.y=column;
        queue.push(input);
        grid[row][column] = '0'; // change it into 0 first in case adj point's adj points come back and find it is '1'
        
        while(!queue.empty()){
            coordinate temp = queue.front();
            queue.pop();
            int init_x = temp.x;
            int init_y = temp.y;
            
            for(int idx=0; idx<4; idx++){ // be careful for this part
                temp.x = init_x + xx[idx];
                temp.y = init_y + yy[idx];
                
                if(out_bound(temp,grid))
                    continue;
                
                if(grid[temp.x][temp.y] == '1'){
                    grid[temp.x][temp.y] = '0';
                    queue.push(temp);
                }
            }
        }
        return;
    }
    
    // function to adjuge point is with boundary
    bool out_bound(coordinate temp, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        return (temp.x<0 || temp.x>=m || temp.y <0 || temp.y >= n);
    }
};
