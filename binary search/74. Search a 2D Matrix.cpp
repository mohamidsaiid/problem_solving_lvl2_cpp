// https://leetcode.com/problems/search-a-2d-matrix/description/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ln = 0, rn = n-1;
        while(ln <= rn)
        {
            int mid = (ln+rn)/2;
            if(matrix[mid][0] <= target && matrix[mid][m-1] >= target)
            {
                return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
            }
            else if(matrix[mid][0] > target) rn = mid - 1;
            else ln = mid + 1;
        }
        return false;
    }
};
