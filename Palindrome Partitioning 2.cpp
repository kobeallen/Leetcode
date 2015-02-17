class Solution {
public:
    void Preprocess(string str, vector<vector<bool> > &palindrome)
    {
        for(int i = 0; i < str.size(); ++i)
            palindrome[i][i] = true;
        for(int i = 0; i < str.size() - 1; ++i)
        {
            if(str[i] == str[i+1])
                palindrome[i][i+1] = true;
        }
        for(int length = 3; length <= str.size(); ++length)
        {
            for(int start = 0; start + length - 1 < str.size(); ++start)
            {
                if(str[start] == str[start + length - 1] && palindrome[start+1][start + length - 2] == true)
                    palindrome[start][start+length-1] = true;
            }
        }
    }
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int MAX = 1000000;
        vector<int> dp (s.size(), MAX);
        vector<vector<bool> > palindrome (s.size(), vector<bool> (s.size(), false));
        Preprocess(s, palindrome);
        dp[0] = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            if(palindrome[0][i] == true)
            {
                dp[i] = 0;
                continue;
            }
            for(int j = 0; j < i; ++j)
            {
                if(dp[j] != MAX)
                {
                    if(palindrome[j+1][i] == true)
                    {
                        if(dp[j] + 1 < dp[i])
                            dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};
