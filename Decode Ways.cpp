class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = s.size();
        if(size == 0)
            return 0;
        int dp[size + 1];
        for(int i = 0; i <= size; ++i)
            dp[i] = 0;
        dp[0] = 1;
        for(int i = 1; i <= size; ++i)
        {
            if(s[i-1] != '0')
                dp[i] = dp[i-1];                      
            if(i >= 2)
            {
                int num = 10*(s[i-2]-'0') + s[i-1] -'0';
                if(num >= 10 && num <= 26)
                    dp[i] += dp[i-2];
            }
        }
        for(int i = 1; i <= size; ++i)
        {
            if(dp[i] == 0)
                return 0;
        }
        return dp[size];
    }
};