class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> ST;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                ST.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(!ST.empty() && ST.top() == '(')
                {
                    ST.pop();
                }
                else
                    return false;
            }
            else if(s[i] == ']')
            {
                if(!ST.empty() && ST.top() == '[')
                {
                    ST.pop();
                }
                else
                    return false;
            }
            else
            {
                if(!ST.empty() && ST.top() == '{')
                {
                    ST.pop();
                }
                else
                    return false;
            }
        }
        return ST.empty();
    }
};