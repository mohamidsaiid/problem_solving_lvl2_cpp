// https://leetcode.com/problems/subsets-ii/description/
class Solution {
public:
    set<vector<int>> subs;
    void search(int k, int n, vector<int> x, vector<int> subset)
    {
        if(n == k) subs.insert(subset);
        else
        {
            search(k+1, n, x, subset);
            subset.push_back(x[k]);
            search(k+1, n, x, subset);
        }        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        search(0, nums.size(), nums, {});
        for(auto i: subs) res.push_back(i);
        return res;
    }
};
