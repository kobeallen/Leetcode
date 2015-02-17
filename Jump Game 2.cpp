class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(n, 0);
        dp[0] = 0;
        int max_index = 0;
        for(int i = 0; i < n; ++i)
        {
            int index = i + A[i];
            if(index > max_index)
            {
                for(int j = max_index + 1; j <= index && j < n; ++j)
                {
                    dp[j] = dp[i] + 1;
                }
                max_index = index < n ? index : n;
            }
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        int jump = 0;
        int now = 0;
        int max = 0;
        while(max < n - 1)
        {
            int tmp = max;
            for(int i = now; i <= max; ++i)
            {
                if(tmp < i + A[i])
                    tmp = i + A[i];
            }
            now = max + 1;
            max = tmp;
            ++jump;            
        }
        return jump;
    }
};
