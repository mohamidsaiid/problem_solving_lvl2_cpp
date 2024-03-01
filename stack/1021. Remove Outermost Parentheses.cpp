// https://leetcode.com/problems/remove-outermost-parentheses/
class Solution {
public:
    string removeOuterParentheses(string s) {
        string x = "";
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            int l = 0, r = 0;
            if(s[i] == '(') l = 1;
            int j = i+1;
            while(l > 0 && j < size)
            {
                if(s[j] == '(') ++l;
                if(s[j] == ')') --l;
                if(l == 0) 
                {
                    x.append(s.substr(i+1, j - i - 1));
                    i = j;
                    break;
                }
                ++j;
            }
        }
        return x;
    }
};
