// https://leetcode.com/problems/palindrome-partitioning/ 
class Solution {
public:
    bool check(string s)
    {
        int l = 0, r = s.size()-1;
        while(l != r && l < r)
        {
            if(s[l] != s[r]) return false;
            --r;
            ++l;
        }
        return true;
    }
    vector<vector<string>> subs;
    void search(int k, int n, string s, vector<string> x)
    {
        if(k == n)
        {
            subs.push_back(x);
            return;
        }
        for(int i = k; i < n; i++)
        {
            string tmp = s.substr(k, i - k +1);
            if(!check(tmp)) continue;
            x.push_back(tmp);
            search(i+1, n, s, x);
            x.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        search(0, s.size(), s, {});
        return subs;
    }
};
