// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> subs;
    vector<int> subset;
    void search(int k, int n, int target, vector<int> cand, int sum)
    {
        if(k >= n) return;
        if(sum == target) 
        {
            subs.push_back(subset);
        }
        else if(sum > target) return;
        else{
        subset.push_back(cand[k]);
        search(k, n, target, cand, sum + cand[k]);
        subset.pop_back();
        search(k+1, n, target, cand, sum);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        search(0, candidates.size(), target, candidates, 0);
        return subs;
    }
};
