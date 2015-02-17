class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp;
        dp.resize(n);
        dp[0]=A[0];
        int i;
        for(i=1;i<n;i++)
        {
            if(dp[i-1]<0)
                dp[i]=A[i];
            else
                dp[i]=dp[i-1]+A[i];
        }
        int ans=-1000000;
        for(i=0;i<n;i++)
        {
            if(ans<dp[i])
                ans=dp[i];
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 0;
        int ans = A[0], previous = A[0];
        for(int i = 1; i < n; ++i)
        {
            if(previous > 0)
                previous += A[i];
            else
                previous = A[i];
            if(ans < previous)
                ans = previous;
        }
        return ans;
    }
};
