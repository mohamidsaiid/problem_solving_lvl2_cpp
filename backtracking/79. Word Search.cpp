// https://leetcode.com/problems/word-search/description/
class Solution {
public:
    bool search(vector<vector<char>> &board, string w, int index, int i, int j)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != w[index]) return false;
        if(w.size() == index+1) return true;
        board[i][j] = '#';
        if(search(board, w, index+1, i+1,j) || search(board, w, index+1, i,j + 1) || search(board,w,index + 1,i-1,j) || search(board,w,index + 1,i,j-1))
            return true;
        board[i][j] = w[index];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int size = board.size(), sizec = board[0].size();
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < sizec; ++j)
            {
                if(board[i][j] == word[0]) 
                    if(search(board,word,0,i,j))
                        return true;
            }
        }
        return false;
    }
};
