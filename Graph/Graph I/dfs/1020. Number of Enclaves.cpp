// https://leetcode.com/problems/number-of-enclaves/
class Solution {
public:
    int n, m;
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) return 0;
        grid[i][j] = 2;
        return dfs(i+1, j, grid) + dfs(i-1, j, grid) + dfs(i, j+1, grid) + dfs(i, j-1, grid) + 1;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int reached_ones = 0, all_ones = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) 
                if(grid[i][j] == 1) all_ones++;
        for(int i = 0; i < n; i++)
        {
            reached_ones += dfs(i, 0, grid);
            reached_ones += dfs(i, m-1, grid);        
        }
        for(int j = 0; j < m; j++)
        {
            reached_ones += dfs(0, j, grid);
            reached_ones += dfs(n-1, j, grid);        
        }
        cout << all_ones <<' ' << reached_ones;
        return all_ones - reached_ones;
    }
};
