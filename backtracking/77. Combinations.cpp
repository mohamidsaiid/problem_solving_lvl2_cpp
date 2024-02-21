// https://leetcode.com/problems/combinations/
class Solution {
public:
    vector<vector<int>> subs;
    vector<int> subset;
    void search(int k, int n, int t)
    {
        if(k == n)
        {
            if(subset.size() == t) subs.push_back(subset);
        }
        else
        {
            search(k+1,n, t);
            subset.push_back(k);
            search(k+1,n,t);
            subset.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        search(1, n+1,k);
        return subs;
    }
};
