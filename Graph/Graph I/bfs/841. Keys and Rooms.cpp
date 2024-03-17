// https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    int bfs(int start, vector<vector<int>> adjlst)
    {
        int cnt = 1;
        queue<int> q;
        vector<bool> visited(adjlst.size(), false);
        q.push(start);
        visited[start] = true;
        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            for(auto it : adjlst[current])
            {
                if(visited[it]) continue;
                q.push(it);
                visited[it] = true;
            ++cnt;
            }
        }
        cout << cnt << ' ';
        return cnt;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(bfs(0, rooms) == n) return true;
        return false;
    }
};
