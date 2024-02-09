// https://leetcode.com/problems/decode-string/
class Solution {
public:
        
    string insertinstring(string x, string y, int s, int e)
    {
        string temp = "";
        int sizex = x.size();
        int sizey = y.size();
        for (int i = 0; i < s; i++)
            temp.push_back(x[i]);
        for (int i = 0; i < sizey; i++)
            temp.push_back(y[i]);
        for (int i = e; i < sizex; i++)
            temp.push_back(x[i]);
        return temp;
    }
    bool check(string s)
    {
        for(auto i : s) if(isdigit(i)) return false;
        return true;
    }
    string f(string s)
    {
        string temps = s;
        if(check(s)) return s; 
        string ns = "";
        int size = s.size();
        int t = 0, j = size + 1, l = 0;
        for (int i = 0; i < size; i++)
        {
            while (isdigit(s[i]) && j > size)
            {
                if (t == 0)
                    t = s[i] - '0';
                else
                    t = t * 10 + (s[i] - '0');
                ++i;
            }
            if (s[i] == '[' && j > size)
                j = i + 1;
            else if(s[i] == '[')
            {
                l = 2;
                ++i;
                while(l > 0)
                {
                    if(s[i] == '[') ++l;
                    if(s[i] == ']') 
                    {
                        --l;
                        if( l == 0 ) break;
                    }
                    ++i;
                }
                string temp = f(s.substr(j, i - j ));
                s = insertinstring(s, temp, j, i);
                size = s.size();
                j = size + 1;
                i = 0;
            }
            else if (s[i] == ']')
            {
                string x = s.substr(j, i - j);
                for (int it = 0; it < t; ++it)
                    ns.append(x);
                t = 0;
                j = size + 1;
            }
            else if (j > size && t == 0)
            {
                ns.push_back(s[i]);
            }
        }
        if(temps != s) return f(s);
        return ns;
    }
    string decodeString(string s) {
        return f(s);
    }
};class Solution {
public:
        
    string insertinstring(string x, string y, int s, int e)
    {
        string temp = "";
        int sizex = x.size();
        int sizey = y.size();
        for (int i = 0; i < s; i++)
            temp.push_back(x[i]);
        for (int i = 0; i < sizey; i++)
            temp.push_back(y[i]);
        for (int i = e; i < sizex; i++)
            temp.push_back(x[i]);
        return temp;
    }
    bool check(string s)
    {
        for(auto i : s) if(isdigit(i)) return false;
        return true;
    }
    string f(string s)
    {
        string temps = s;
        if(check(s)) return s; 
        string ns = "";
        int size = s.size();
        int t = 0, j = size + 1, l = 0;
        for (int i = 0; i < size; i++)
        {
            while (isdigit(s[i]) && j > size)
            {
                if (t == 0)
                    t = s[i] - '0';
                else
                    t = t * 10 + (s[i] - '0');
                ++i;
            }
            if (s[i] == '[' && j > size)
                j = i + 1;
            else if(s[i] == '[')
            {
                l = 2;
                ++i;
                while(l > 0)
                {
                    if(s[i] == '[') ++l;
                    if(s[i] == ']') 
                    {
                        --l;
                        if( l == 0 ) break;
                    }
                    ++i;
                }
                string temp = f(s.substr(j, i - j ));
                s = insertinstring(s, temp, j, i);
                size = s.size();
                j = size + 1;
                i = 0;
            }
            else if (s[i] == ']')
            {
                string x = s.substr(j, i - j);
                for (int it = 0; it < t; ++it)
                    ns.append(x);
                t = 0;
                j = size + 1;
            }
            else if (j > size && t == 0)
            {
                ns.push_back(s[i]);
            }
        }
        if(temps != s) return f(s);
        return ns;
    }
    string decodeString(string s) {
        return f(s);
    }
};
