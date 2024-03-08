// https://www.codingninjas.com/studio/problems/creating-and-printing_1214551?leftPanelTabValue=PROBLEM
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> adjlist(n);
    for(int i = 0; i < n; i++)
    {
        adjlist[i].push_back(i);
    }
    for(int i = 0;i < m; i++)
    {
        adjlist[edges[i][0]].push_back(edges[i][1]);
        adjlist[edges[i][1]].push_back(edges[i][0]);
    }
    return adjlist;
}
