class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(grid.empty())
            return 0;
        int row = grid.size(), col = grid[0].size();
        vector<vector<int> > dp(row, vector<int>(col, 100000));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < col; ++i)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        for(int i = 1; i < row; ++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        int result;
        for(int i = 1; i< row; ++i)
        {
            for(int j = 1; j < col; ++j)
            {
                result = dp[i-1][j] + grid[i][j];
                if(dp[i][j] > result)
                    dp[i][j] = result;
                result = dp[i][j-1] + grid[i][j];
                if(dp[i][j] > result)
                    dp[i][j] = result;
            }
        }
        return dp[row-1][col-1];
    }
};
