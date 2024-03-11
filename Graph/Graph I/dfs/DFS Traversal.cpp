// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?leftPanelTabValue=PROBLEM
void dfs(vector<int> &res,int N, vector<vector<int>> adjlst,vector<bool> &visited)
{
    visited[N] = true;
    res.push_back(N);
    for(int i = 0; i< adjlst[N].size();i++)
    {
        int tmp = adjlst[N][i];
        if(!visited[tmp]) dfs(res,tmp, adjlst, visited);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adjlst(V);
    for(int i = 0; i < E; i++)
    {
        int f = edges[i][0];
        int t = edges[i][1];
        adjlst[f].push_back(t);
        adjlst[t].push_back(f);
    }
    vector<vector<int>> res;
    //res.push_back({0});
    vector<bool> visited(V,false);
    for(int i = 0; i < V; i++)
    {
        if(visited[i]) continue;
        vector<int> tmp;
        dfs(tmp, i, adjlst, visited);
        res.push_back(tmp);
    }
    //res[0][0] = res.size()-1;
    return res;
}
