class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0)
        {
            if(*p == 0)
                return true;
            if(*p == '*')
                return isMatch(s, p + 1);
            else
                return false;
        }
        if(*p == 0)
            return false;
        if(*p == '*')
        {
            if(isMatch(s, p + 1) == true)
                return true;
            else
                return isMatch(s + 1, p);
        }
        else if(*p == '?')
        {
            return isMatch(s + 1, p + 1);
        }
        else
        {
            if(*s == *p)
                return isMatch(s + 1, p + 1);
            else
                return false;
        }
    }
};

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size_s = strlen(s);
        int size_p = strlen(p);
        int dp[size_s+1][size_p+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(int i = 1; i <= size_p; ++i)
        {
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-1];
        }
        //int now = 0, next = 1;
        for(int i = 1; i <= size_s; ++i)
        {
            for(int j = 1; j <= size_p; ++j)
            {
                if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
                }
                else if(p[j-1] == '?' || s[i-1] == p[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
            //now = (now + 1) % 2;
            //next = (next + 1) % 2;
        }
        return dp[size_s][size_p];
    }
};