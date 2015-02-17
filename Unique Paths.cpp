class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		int dp[m][n];
		memset(dp,0,sizeof(dp));
		if(m==1||n==1)
			return 1;
		int i,j;
		int x,y;
		x=1,y=0;
		dp[0][0]=1;
		while(1)
		{
			i=x, j=y;
			while(i>=0&&j<n)
			{
				if(i-1>=0)
					dp[i][j]+=dp[i-1][j];
				if(j-1>=0)
					dp[i][j]+=dp[i][j-1];
				if(i==m-1&&j==n-1)
					return dp[m-1][n-1];
				i--,j++;
			}
			if(x!=m-1)
				x++;
			else
				y++;
		}
	}
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
            dp[i][0] = 1;
        for(int i = 0; i < n; ++i)
            dp[0][i] = 1;
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};