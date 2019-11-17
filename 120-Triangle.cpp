//u can use array:
//int f[triangle.size()][triangle.size()];


class Solution {
public: // method of DP: from top to botton
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> temp (n, 0);
        vector<vector<int>> res (n, temp);
        //int res[n][n];
        
        res[0][0] = triangle[0][0];
        if(n == 1)
            return res[0][0];
        
        for(int i = 1; i < n; i++) // need to deal with two edge cases
        {
            res[i][0] = res[i - 1][0] + triangle[i][0];
            res[i][i] = res[i - 1][i - 1] + triangle[i][i];
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < i; j++)
                res[i][j] = min(res[i - 1][j - 1], res[i - 1][j]) + triangle[i][j];
        }
        
        int Min = res[n - 1][0];
        for(int i = 1; i < n; i++)
        {
            if(Min > res[n - 1][i])
                Min = res[n - 1][i];
        }
        return Min;
    }
};



class Solution {
public: // method of DP: from botton to top
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> temp (n, 0); // temp must initial !!
        vector<vector<int>> res (triangle.size(), temp); // size and value
        
        for(int i = 0; i < n; i++) // initial for botton raw
        {
            res[n - 1][i] = triangle[n - 1][i];
        }
        
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                res[i][j] = min(res[i + 1][j], res[i + 1][j + 1]) + triangle[i][j];
            }
        }
        
        return res[0][0];
    }
};


class Solution {
public: // divide conquer + memorization
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> temp (triangle[ triangle.size() - 1 ].size(), INT_MAX);
        vector<vector<int>> memory (triangle.size(), temp);
        
        return divideconquer(0, 0, triangle, memory);
    }
    
    int divideconquer(int x, int y, vector<vector<int>>& triangle, vector<vector<int>> &memory)
    {
        if(x == triangle.size())
            return 0;
        
        if(memory[x][y] != INT_MAX) // check first
            return memory[x][y];
        
        memory[x][y] = triangle[x][y] + min(divideconquer(x + 1, y, triangle, memory), divideconquer(x + 1, y + 1, triangle, memory)); // save it in memory
        
        return memory[x][y];
    }
};


class Solution {
public: // method of divide conquer: O(2^n)
    int minimumTotal(vector<vector<int>>& triangle) {
        return dividconquer(0, 0, triangle);
    }
    
    int dividconquer(int x, int y, vector<vector<int>>& triangle) // return min sum
    {
        if(x == triangle.size())
            return 0;
        
        return triangle[x][y] + min(dividconquer(x + 1, y, triangle), dividconquer(x + 1, y + 1, triangle));
    }
};


class Solution {
public: // traverse method: O(2^n) time complexicity
    int minimumTotal(vector<vector<int>>& triangle) {
        traverse(0, 0, 0, triangle);
        return best;
    }
    
    void traverse(int x, int y, int sum, vector<vector<int>>& triangle)
    {
        if(x == triangle.size()) //traverse exit part
        {
            if(sum < best)
                best = sum;
            return;
        }
        
        traverse(x + 1, y, sum + triangle[x][y], triangle);
        traverse(x + 1, y + 1, sum + triangle[x][y], triangle);
        return;
    }
    
private:
    int best = INT_MAX;
};
