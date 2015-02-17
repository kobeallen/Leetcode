class Solution {
public:
    bool isPalindrome(string str, int start, int end)
    {
        while(start < end)
        {
            if(str[start] != str[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
    
    void DFS(string str, int pos, int depth, vector<string> &result, vector<vector<string> > &ans)
    {
        if(pos >= str.size())
        {
            ans.push_back(result);
            return ;
        }
        int start = pos, end = pos;
        while(end < str.size())
        {
            if(isPalindrome(str, start, end))
            {
                string tmp (str, start, end - start + 1);
                result.push_back(tmp);
                DFS(str, end + 1, depth + 1, result, ans);
                result.pop_back();
            }
            ++end;
        }
    }
    
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ans;
        vector<string> result;
        DFS(s, 0, 0, result, ans);
        return ans;
    }
};


class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size = s.size();
        vector<vector<bool> > palindrome(size, vector<bool>(size, false));
        for(int i = 0; i < size; ++i)
            palindrome[i][i] = true;
        for(int i = 0; i < size - 1; ++i)
            palindrome[i][i+1] = s[i] == s[i+1] ? true : false;
        for(int length = 3; length <= size; ++length)
        {
            for(int i = 0; i + length - 1 < size; ++i)
            {
                int j = i + length - 1;
                if(s[i] == s[j] && palindrome[i+1][j-1] == true)
                    palindrome[i][j] = true;
            }
        }
        vector<vector<vector<string> > > ans(size, vector<vector<string> >());
        ans[size-1] = vector<vector<string> >(1, vector<string>(1, s.substr(size-1, 1)));
        for(int i = size - 2; i >= 0; --i)
        {
            for(int j = i; j < size; ++j)
            {
                if(palindrome[i][j] == true)
                {
                    vector<string> LEFT(1, s.substr(i, j-i+1));
                    if(j != size - 1)
                    {
                        for(int k = 0; k < ans[j+1].size(); ++k)
                        {
                            vector<string> tmp;
                            tmp.push_back(LEFT[0]);
                            tmp.insert(tmp.end(), ans[j+1][k].begin(), ans[j+1][k].end());
                            ans[i].push_back(tmp);
                        }
                    }
                    else
                    {
                        ans[i].push_back(LEFT);
                    }
                }
            }
        }
        return ans[0];
    }
};
