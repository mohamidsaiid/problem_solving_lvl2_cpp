// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> s;
        int size = strs.size();
        for(int i = 0; i < size; i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            s[temp].push_back(i);
        }
        vector<vector<string>> t;
        for(auto i : s)
        {
            vector<string> temp;
            int ss = i.second.size();
            for (int j = 0; j < ss; j++)
                temp.push_back(strs[i.second[j]]);
            t.push_back(temp);
        }
        return t;
    }
};
