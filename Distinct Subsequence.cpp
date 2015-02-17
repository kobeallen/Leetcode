class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size1 = T.size(), size2 = S.size();
        int dp[size1+1][size2+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= size2; ++i)
        {
            dp[0][i] = 1;
        }
        for(int i = 1; i <= size1; ++i)
        {
            for(int j = i; j <= size2; ++j)
            {
                if(T[i-1] == S[j-1])
                {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[size1][size2];
    }
};

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size_t = T.size(), size_s = S.size();
        if(size_t > size_s)
            return 0;
        else if(size_t == size_s)
        {
            if(S == T)
                return 1;
            else
                return 0;
        }
        vector<vector<int> > dp(size_t, vector<int>(size_s, 0));
        dp[0][0] = S[0] == T[0] ? 1 : 0;
        for(int i = 1; i < size_s; ++i)
        {
            if(T[0] == S[i])
                dp[0][i] = dp[0][i-1] + 1;
            else
                dp[0][i] = dp[0][i-1];
        }
        for(int i = 1; i < size_t; ++i)
        {
            for(int j = i; j < size_s; ++j)
            {
                dp[i][j] = dp[i][j-1];
                if(T[i] == S[j])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[size_t-1][size_s-1];
    }
};
