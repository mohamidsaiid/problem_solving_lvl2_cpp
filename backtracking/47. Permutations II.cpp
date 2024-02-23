// https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    vector<vector<int>> perm;
    void search(int k, int n, vector<int> nums, vector<int> p, vector<bool> &c)
    {
        if(k == n) 
        {
            perm.push_back(p);
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(c[i] || (i > 0 && nums[i] == nums[i-1] && c[i-1])) continue;
            c[i] = true;
            p.push_back(nums[i]);
            search(k+1, n, nums, p, c);
            c[i] = false;
            p.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> c(nums.size(),false);
        sort(nums.begin(),nums.end());
        search(0,nums.size(), nums, {}, c);
        return perm;
    }
};
