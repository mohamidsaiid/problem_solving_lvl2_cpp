// https://leetcode.com/problems/daily-temperatures/description/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> x(size,0);
        stack<int> stk;
        stack<int> temp;
        for(int i = 0; i < size; i++)
        {
            bool c = 0;
            if(stk.empty() || stk.top() > temperatures[i])
            {
                stk.push(temperatures[i]);
                temp.push(i);
            }
            else
            {
                int prev = 0;
                while( !stk.empty() && stk.top() < temperatures[i] )
                {
                    prev = temp.top();
                    temp.pop();
                    stk.pop();
                    x[prev] = i - prev;
                    c = 1;
                }
                if(c) x[prev] =  i - prev;
                stk.push(temperatures[i]);
                temp.push(i);
            }
        }
        return x;
    }
};
