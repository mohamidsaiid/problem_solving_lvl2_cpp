// https://www.codingninjas.com/studio/problems/find-the-number-of-states_1377943?leftPanelTabValue=SUBMISSION
void dfs( int N, vector<vector<int>> adjlst, vector<bool> &visisted)
{
    visisted[N] = true;
    for(int i = 0; i < adjlst[N].size(); i++)
    {
        int tmp = adjlst[N][i];
        if(!visisted[tmp])
        {
            dfs(tmp, adjlst, visisted);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.
    vector<bool> visited(n, false);
    vector<vector<int>> adjlst(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(roads[i][j] == 1 && i != j) adjlst[i].push_back(j);
        }
    }
    int cntt = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == true)continue; 
        dfs(i, adjlst, visited);
        cntt++;
    }
    return cntt;
}
