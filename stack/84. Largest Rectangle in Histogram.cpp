// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // both stackes is going to be montonicly increasing
        stack <pair<int, int>> stk;
        stack<int> area;
        int size = heights.size();
        int maxx = 0;
        for(int i = 0; i < size; i++)
        {
            int t = i;
            if(stk.empty())
            {
                stk.push({heights[i], i});
                continue;
            }
            while(!stk.empty() && heights[i] < stk.top().first)
            {
                int width = i - stk.top().second;
                maxx = max(maxx, stk.top().first * width);
                t = stk.top().second;
                stk.pop();
            }
            stk.push({heights[i], t});
        }
        while(!stk.empty())
        {
            int width = size - stk.top().second;
            maxx = max(maxx, stk.top().first * width);
            stk.pop();
        }
        return maxx;
    }
};
