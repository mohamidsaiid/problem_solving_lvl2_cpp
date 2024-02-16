// https://leetcode.com/problems/subsets/description/
class Solution {
public:
    vector<int> subset;
    vector<vector<int>> ss;
    void search(int k, vector<int> x, int n)
    {
        if(k == n) 
        {
            ss.push_back(subset);
        }
        else
        {
            search(k+1, x, n);
            subset.push_back(x[k]);
            search(k+1, x, n);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 1) return {{},{nums[0]}};
        search(0, nums, nums.size());
        return ss;
    }
};
