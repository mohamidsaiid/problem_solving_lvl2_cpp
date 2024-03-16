// https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    int path_i[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
    int path_j[8] = {0, 0, 1, -1, -1, 1, -1, 1};
    
    bool vaild(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j < m && j >= 0);
    }
    int bfs(vector<vector<int>> grid)
    {
        bool flag = false;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        map<pair<int,int>, pair<int,int>> came_from;
        q.push({0,0});
        came_from[{0, 0}] = {0, 0};
        while(!q.empty())
        {
            pair<int,int> current = q.front();
            int crnti = current.first, crntj = current.second;
            if(crnti == n-1 && crntj == m-1) 
            {
                flag = true;
                break;
            }
            vector<pair<int,int>> neighbors;
            for(int i = 0; i < 8; i++)
            {
                int adjx = crnti + path_i[i], adjy = crntj + path_j[i];
                if(!vaild(adjx, adjy, n, m)) continue;
                neighbors.push_back({adjx, adjy});
            }
            for(auto it : neighbors)
            {
                auto tmp = came_from.find({it.first, it.second});
                if(tmp != came_from.end() || grid[it.first][it.second] == 1) continue;
                q.push({it.first, it.second});
                came_from[{it.first, it.second}] = {crnti, crntj}; 
            }
            q.pop();
        }
        if(!flag) return -1;
        vector<int> path;
        int endi = n-1, endj = m-1, starti = 0, startj = 0;
        while(endi != starti || endj != startj)
        {
            path.push_back(1);
            auto tmp = came_from[{endi, endj}];
            endi = tmp.first;
            endj = tmp.second;
        }
        return path.size()+1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1) return -1;
        return bfs(grid);
    }
};
