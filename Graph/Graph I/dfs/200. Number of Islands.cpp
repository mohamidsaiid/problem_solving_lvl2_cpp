// https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    bool valid(int i, int j, int n, int m)
    {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if(!valid(i, j, n, m)) return;
        if(grid[i][j] == '0') return ;
        grid[i][j] = '0';
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(),cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] != '1' ) continue;
                dfs(i,j, grid);
                ++cnt;
            }
        }
        return cnt;
    }
};
