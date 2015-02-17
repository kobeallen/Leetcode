class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1=s1.size(), len2=s2.size();
        if(len1!=len2)
            return false;
        int length,i,j,k;
        vector<vector<vector<bool> > > dp;
        dp.resize(len1+1);
        for(i=0;i<=len1;i++)
        {
            dp[i].resize(len1+1);
            for(j=0;j<=len1;j++)
                dp[i][j].resize(len1+1);
        }
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(s1[i]==s2[j])
                    dp[i][j][1]=true;
            }
        }
        for(length=2;length<=len1;length++)
        {
            for(i=0;i+length-1<len1;i++)
            {
                for(j=0;j+length-1<len2;j++)
                {
                    for(k=1;k<length;k++)
                    {
                        if(dp[i][j][k]==true&&dp[i+k][j+k][length-k]==true)
                            dp[i][j][length]=true;
                        if(dp[i][j+length-k][k]==true&&dp[i+k][j][length-k]==true)
                            dp[i][j][length]=true;
                    }
                }
            }
        }
        return dp[0][0][len1];
    }
};






class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1.size() != s2.size())
            return false;
        int length = s1.size();
        bool dp[length + 1][length + 1][length + 1];
        for(int i = 0; i <= length; ++i)
        {
            for(int j = 0; j <= length; ++j)
            {
                for(int k = 0; k <= length; ++k)
                    dp[i][j][k] = false;
            }
        }
        for(int i = 0; i < length; ++i)
        {
            for(int j = 0; j < length; ++j)
            {
                if(s1[i] == s2[j])
                    dp[i][j][1] = true;
            }
        }
        for(int len = 2; len <= length; ++len)
        {
            for(int i = 0; i + len - 1 < length; ++i)
            {
                for(int j = 0; j + len -1 < length; ++j)
                {
                    for(int k = 1; k <= len; ++k)
                    {
                        if(dp[i][j][k] == true && dp[i+k][j+k][len-k] == true)
                            dp[i][j][len] = true;
                        if(dp[i][j+len-k][k] == true && dp[i+k][j][len-k] == true)
                            dp[i][j][len] = true;
                    }
                }
            }
        }
        return dp[0][0][length];
    }
};
