// https://leetcode.com/problems/surrounded-regions/submissions/1201581235/
class Solution {
public:
    bool valid_pos(int i, int j, int n, int m)
    {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>> &board)
    {
        if(!valid_pos(i, j, n, m)) return;
        if(board[i][j] != 'O') return;
        board[i][j] = 'T';
        dfs(i+1, j, n, m, board);
        dfs(i-1, j, n, m, board);
        dfs(i, j-1, n, m, board);
        dfs(i, j+1, n, m, board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            dfs(i, 0, n, m, board);
            dfs(i, m-1, n, m, board);
        }
        for(int j = 0; j < m; j++)
        {
            dfs(0, j, n, m, board);
            dfs(n-1, j, n, m, board);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
