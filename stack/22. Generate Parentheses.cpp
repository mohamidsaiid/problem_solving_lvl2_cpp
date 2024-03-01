// https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
bool isValid(string s)
{
    stack<char> x;
    int size = s.length();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            x.push(s[i]);
        }
        else if (!x.empty() && ((s[i] == '}' && x.top() == '{') || (s[i] == ')' && x.top() == '(') || (s[i] == ']' && x.top() == '[')))
        {
            x.pop();
        }
        else
            return false;
    }
    return x.empty();
}

    vector<string> generateParenthesis(int n) {
        string x = "";
        for(int i = 0; i < n ; i++)
        {
            x.push_back('(');
            x.push_back(')');
        }
        sort(x.begin(), x.end());
        vector<string> temp;
        do
        {
            if(isValid(x)) temp.push_back(x);
        }while(next_permutation(x.begin(), x.end()));
        return temp;
    }
};
