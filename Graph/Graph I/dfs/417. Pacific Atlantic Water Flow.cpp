// https://leetcode.com/problems/pacific-atlantic-water-flow/description/
class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>> hghts, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;
        if(i > 0 && !visited[i-1][j] && hghts[i][j] <= hghts[i-1][j]) dfs(i-1, j, n, m, hghts, visited);
        if(i < n-1 && !visited[i+1][j] && hghts[i][j] <= hghts[i+1][j]) dfs(i+1, j, n, m, hghts, visited);
        if(j > 0 && !visited[i][j-1] && hghts[i][j] <= hghts[i][j-1]) dfs(i, j-1, n, m, hghts, visited);
        if(j < m-1 && !visited[i][j+1] && hghts[i][j] <= hghts[i][j+1]) dfs(i, j+1, n, m, hghts, visited);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<int>> res;
        for(int i = 0; i < n; i++)
        {
            dfs(i, 0,n, m, heights, pacific);
            dfs(i, m-1,n, m, heights, atlantic);
        }
        for(int j = 0; j < m; j++)
        {
            dfs(0, j,n,m, heights, pacific);
            dfs(n-1, j,n,m, heights, atlantic);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
