class Solution {
public:
    int DFS(int num, vector<int> &dp)
    {
        if(dp[num] != -1)
            return dp[num];
        int sum = 0, left, right;
        for(int i = 1; i <=num; ++i)
        {
            left = DFS(i - 1, dp);
            right =DFS(num - i, dp);
            sum = sum + left * right;
        }
        dp[num] = sum;
        return dp[num];
    }
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp;
        for(int i = 0; i <= n; ++i)
            dp.push_back(-1);
        dp[0] = 1;
        int ans = DFS(n, dp);
        return ans;
    }
};