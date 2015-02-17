class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        bool dp[size1+1][size2+1];
        if(size1 + size2 != size3)
            return false;
        for(int i = 0; i <= size1; ++i)
        {
            for(int j = 0; j <=size2; ++j)
                dp[i][j] = false;
        }
        dp[0][0] = true;
        for(int i = 1; i <= size1; ++i)
        {
            if(s1[i-1] == s3[i-1])
                dp[i][0] = dp[i-1][0];
            else
                dp[i][0] = false;
        }
        for(int i = 1; i <= size2; ++i)
        {
            if(s2[i-1] == s3[i-1])
                dp[0][i] = dp[0][i-1];
            else
                dp[0][i] = false;
        }
        for(int i = 1; i <= size1; ++i)
        {
            for(int j = 1; j <= size2; ++j)
            {
                dp[i][j] = false;
                if(s1[i-1] == s3[i+j-1])
                {
                    if(dp[i-1][j] == true)
                        dp[i][j]=true;
                }
                if(s2[j-1] == s3[i+j-1])
                {
                    if(dp[i][j-1] == true)
                        dp[i][j]=true;
                }
            }
        }
        return dp[size1][size2];
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        if(size1 + size2 != size3)
            return false;
        vector<vector<bool> > dp(size1 + 1, vector<bool>(size2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= size1; ++i)
        {
            if(s1.substr(0, i) == s3.substr(0, i))
                dp[i][0] = true;
        }
        for(int i = 1; i <= size2; ++i)
        {
            if(s2.substr(0, i) == s3.substr(0, i))
                dp[0][i] = true;
        }
        for(int i = 1; i <= size1; ++i)
        {
            for(int j = 1; j <= size2; ++j)
            {
                if(s1[i - 1] == s3[i + j - 1])
                {
                    if(dp[i-1][j] == true)
                        dp[i][j] = true;
                }
                if(s2[j - 1] == s3[i + j - 1])
                {
                    if(dp[i][j-1] == true)
                        dp[i][j] = true;
                }
            }
        }
        return dp[size1][size2];
    }
};
