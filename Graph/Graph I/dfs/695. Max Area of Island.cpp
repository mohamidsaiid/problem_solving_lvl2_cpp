// https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
    bool valid(int i, int j, int n, int m)
    {
        return (i >= 0 && j >= 0 && j < m && i < n);
    }
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if(!valid(i, j, n, m)) return 0;
        if(grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return dfs(i+1, j, grid) + dfs(i-1, j, grid) + dfs(i, j+1, grid) + dfs(i, j-1, grid) + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(),maxx = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0) continue;
                maxx = max(maxx, dfs(i, j, grid)); 
            }
        }
        return maxx;
    }
};
