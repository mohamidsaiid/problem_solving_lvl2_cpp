// https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> subs;
    vector<int> subset;
    void search(int k, int n, vector<int> x, int target)
    {
        if(target == 0)
        {
            subs.push_back(subset);
            return;
        }
        else if(target < 0) return;
        if(k >= n) return;
        subset.push_back(x[k]);
        search(k+1, n, x, target - x[k]);
        subset.pop_back();
        while(k+1 < n && x[k] == x[k+1]) k++;
        search(k+1, n, x, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        search(0, candidates.size(), candidates, target);
        
        return subs;
    }
};
