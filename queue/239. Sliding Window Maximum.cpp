// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> wind;
        for (int i = 0; i < k; i++)
        {
            while (!wind.empty() && nums[i] > wind.back().first)
                wind.pop_back();
            wind.push_back({nums[i], i});
        }
        vector<int> res;
        int l = 0, r =k;
        while(r < nums.size())
        {
            if(wind.front().second < l) wind.pop_front();
            res.push_back(wind.front().first);
            while (!wind.empty() && nums[r] > wind.back().first)
                wind.pop_back();
            wind.push_back({nums[r], r});
            l++;
            r++;
        }
        while(wind.size() > k || wind.front().second < l) wind.pop_front();
        res.push_back(wind.front().first);
        return res;
    }
};
