class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp;
        dp.resize(n);
        dp[0]=1, dp[1]=2;
        for(int i=2;i<n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n-1];
    }
};
