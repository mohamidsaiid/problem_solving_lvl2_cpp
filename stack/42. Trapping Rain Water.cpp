// https://leetcode.com/problems/trapping-rain-water/description/
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> ml(size, 0);
        vector<int> mr(size, 0);
        int m = 0;
        for(int i = 0; i < size; i++)
        {
            m = max(m,height[i]);
            ml[i] = m;
        }
        m = 0;
        for(int i = size - 1; i >= 0; i--)
        {
            m = max(m, height[i]);
            mr[i] = m;
        }
        int res = 0;
        for(int i = 0; i < size; i++)
        {
            int minn = min(ml[i], mr[i]);
            minn -= height[i];
            if(minn > 0) res+=minn;
        }
        return res;
    }
};
