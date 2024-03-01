// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:

    pair<int, int> t(stack<int> &x)
    {
        int a = x.top();
        x.pop();
        int b = x.top();
        x.pop();
        return {a,b};
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> x;
        int size = tokens.size();
        for(int i = 0; i < size; i++)
        {
            if(tokens[i] == "+")
            {
                auto ti = t(x);
                x.push(ti.first + ti.second);
            }
            else if(tokens[i] == "-")
            {
                auto ti = t(x);
                x.push(ti.second - ti.first);
            }
            else if(tokens[i] == "*")
            {
                auto ti = t(x);
                x.push(ti.first * ti.second);
            }
            else if(tokens[i] == "/")
            {
                auto ti = t(x);
                x.push(ti.second / ti.first);
            }
            else x.push(stoi(tokens[i]));
        }
        return x.top();
    }
};
