// https://leetcode.com/problems/flood-fill/description/
class Solution {
public:
    bool valid(int i, int j, int n, int m)
    {
        return (i >= 0 && j >= 0 && j < m && i < n);
    }
    void dfs(int i, int j, int color, int orgcolor, vector<vector<int>> &img)
    {
        int n = img.size(), m = img[0].size();
        if(!valid(i, j, n, m)) return;
        if(img[i][j] != orgcolor) return;
        img[i][j] = color;
        dfs(i+1, j, color, orgcolor, img);
        dfs(i-1, j, color, orgcolor, img);
        dfs(i, j+1, color, orgcolor, img);
        dfs(i, j-1, color, orgcolor, img);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgcolor = image[sr][sc];
        if(color == orgcolor) return image;
        dfs(sr, sc, color, orgcolor, image);
        return image;
    }
};
