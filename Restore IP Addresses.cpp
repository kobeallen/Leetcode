class Solution {
public:
    void DFS(int pos, int depth, string s, string result, vector<string> &ans)
    {
        if(depth == 4)
        {
            if(pos == s.size())
                ans.push_back(result);
            return ;
        }
        int num = 0;
        while(1)
        {            
            num = 10 * num + s[pos] - '0';
            result += s[pos];
            ++pos;
            if(num >= 256)
                break;
            if(depth != 3)
                DFS(pos, depth + 1, s, result + '.', ans);
            else
                DFS(pos, depth + 1, s, result, ans);
            if(num == 0)
                break;            
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = s.size();
        vector<string> ans;
        string result;
        if(size < 4 || size > 12)
            return ans;
        DFS(0, 0, s, result, ans);
        return ans;
    }
};