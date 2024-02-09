// https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int>freq;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == nums[i+1])cnt++;
            else
            {
                freq.push_back(cnt);
                cnt=1;
            }
        }
        auto it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        vector<int> temp;
        for (int i = 0; i < k;i++)
        {
            int m = -1;
            int size = freq.size();
            int t = 0;
            for (int i = 0; i < size; i++)
            {
                if (m < freq[i])
                {
                    m = freq[i];
                    t = i;
                }
            }
            freq[t] = 0;
            temp.push_back(nums[t]);
        }
        return temp;
    }
};
