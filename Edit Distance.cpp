class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size1=word1.size(), size2=word2.size();
        int i,j;
        vector<vector<int> > dp;
        if(size1==0)
            return size2;
        if(size2==0)
            return size1;
        dp.resize(size1);
        for(i=0;i<size1;i++)
            dp[i].resize(size2);
        if(word1[0]==word2[0])
            dp[0][0]=0;
        else
            dp[0][0]=1;
        for(i=1;i<size1;i++)
        {
            if(word1[i]==word2[0])
                dp[i][0]=i;
            else
                dp[i][0]=dp[i-1][0]+1;
        }
        for(i=1;i<size2;i++)
        {
            if(word2[i]==word1[0])
                dp[0][i]=i;
            else
                dp[0][i]=dp[0][i-1]+1;
        }
        for(i=1;i<size1;i++)
        {
            for(j=1;j<size2;j++)
            {
                int result=dp[i-1][j]+1;
                if(result>dp[i][j-1]+1)
                    result=dp[i][j-1]+1;
                if(word1[i]==word2[j])
                {
                    if(result>dp[i-1][j-1])
                        result=dp[i-1][j-1];
                }
                else
                {
                    if(result>dp[i-1][j-1]+1)
                        result=dp[i-1][j-1]+1;
                }
                dp[i][j]=result;
            }
        }
        return dp[size1-1][size2-1];
    }
};


class Solution {
public:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
    
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size1 = word1.size();
        int size2 = word2.size();
        if(size1 == 0)
            return size2;
        if(size2 == 0)
            return size1;
        vector<vector<int> > dp(size1 + 1, vector<int>(size2 + 1, 0));
        for(int i = 1; i <= size1; ++i)
            dp[i][0] = i;
        for(int i = 1; i <= size2; ++i)
            dp[0][i] = i;
        for(int i = 1; i <= size1; ++i)
        {
            for(int j = 1; j <= size2; ++j)
            {
                int result = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                if(word1[i-1] == word2[j-1])
                {
                    result = min(result, dp[i-1][j-1]);
                }
                else
                {
                    result = min(result, dp[i-1][j-1] + 1);
                }
                dp[i][j] = result;
            }
        }
        return dp[size1][size2];
    }
};