// https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool dfs(int N, unordered_map<int, vector<int>> &adjlst, unordered_set<int> visited)
    {
        if(visited.find(N) != visited.end()) return false;
        if(adjlst[N].empty()) return true;
        visited.insert(N);
        for(int i = 0; i < adjlst[N].size(); i++)
        {
            int node = adjlst[N][i];
            if(!dfs(node, adjlst, visited)) return false;
        }
        adjlst[N].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        unordered_map<int, vector<int>> adjlst;
        unordered_set<int> visited;
        for(int i = 0; i < n; i++)
        {
           // if(prerequisites[i][0] == prerequisites[i][1]) return false;
            adjlst[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(i, adjlst, visited)) return false;
        }
        return true;
    }
};
