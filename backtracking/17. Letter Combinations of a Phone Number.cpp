// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> subs;
    void search(int k, int n, int idx, string d, string subset, vector<string> c)
    {
        if(subset.size() == n)
        {
            subs.push_back(subset);
            return;
        }
        if(k >= n) return;
        for(int i = 0; i < c[d[idx] - '0' - 2].size(); i++)
        {
            subset.push_back(c[d[idx] - '0' - 2][i]);
            search(k+1, n, idx+1, d, subset, c);
            subset.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {}; 
        vector<string> chars{"abc",
                            "def",
                            "ghi",
                            "jkl",
                            "mno",
                            "pqrs",
                            "tuv",
                            "wxyz"
                            };
        search(0, digits.size(), 0, digits, "", chars);
        return subs;
    }
};
