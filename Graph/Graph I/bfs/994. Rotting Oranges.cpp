// https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int adjx[4] = {1, -1, 0, 0};
    int adjy[4] = {0, 0, 1, -1};
    int n, m;
    int rotten = 0, fresh = 0;
    queue<pair<int,int>> q;
    bool valid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int bfs(vector<vector<int>> grid, int r)
    {
        // if the value of the cell --> 1 get it else continue
        while(!q.empty() && fresh > 0)
        {
            int len = q.size();
            for(int l = 0; l < len; l++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int it = 0; it < 4; it++)
                {
                    int ax = x + adjx[it], ay = y + adjy[it];
                    if(!valid(ax, ay) || grid[ax][ay] != 1) continue;
                    grid[ax][ay] = 2;
                    q.push({ax, ay});
                    --fresh;
                }
            }
            r++;
        }
        return fresh == 0 ? r : -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        // add all the 2 cells into queue
        // count all the rotten and fresh oranges
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2) q.push({i, j}), ++rotten;
                if(grid[i][j] == 1) ++fresh;
            }
        }
        int r = 0;
        int res = bfs(grid, r);
        return res;
    }
};
