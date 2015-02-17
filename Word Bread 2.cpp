class Solution {
public:
    void DFS(vector<vector<int> > next, int id, string s, string result, vector<string> &ans)
    {
        if(id == s.size())
        {
            ans.push_back(result);
            return ;
        }
        for(int i = 0; i < next[id].size(); ++i)
        {
            int j = next[id][i];
            string next_result = result + s.substr(id, j-id);
            if(j != s.size())
                next_result += " ";
            DFS(next, j, s, next_result, ans);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size = s.size();
        vector<bool> dp(size+1, false);
        vector<vector<int> > next(size+1, vector<int>());
        dp[0] = true;
        for(int i = 1; i <= size; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(dp[j] == true && dict.find(s.substr(j, i-j)) != dict.end())
                {
                    dp[i] = true;
                    next[j].push_back(i);
                }
            }
        }
        string result;
        vector<string> ans;
        if(dp[size] == true)
            DFS(next, 0, s, result, ans);
        return ans;
    }
};
