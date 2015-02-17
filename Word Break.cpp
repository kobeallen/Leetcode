class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size = s.size();
        vector<int> dp(size + 1, false);
        dp[0] = true;
        for(int i = 1; i <= size; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(dp[j] == true && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    dp[i] = true;
                }
            }
        }
        return dp[size];
    }
};
