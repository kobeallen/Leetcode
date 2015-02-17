class Solution {
public:
    void DFS(int now, int id, int size, int num, vector<int> &result, vector<vector<int> > &ans)
    {
        if(now==size)
        {
            ans.push_back(result);
            return ;
        }
        for(int i=id;i<=num;i++)
        {
            result[now]=i;
            DFS(now+1, i+1, size, num, result, ans);
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> result;
        result.resize(k);
        DFS(0, 1, k, n, result, ans);
        return ans;
    }
};


class Solution {
public:
    void DFS(int num, int max_num, int depth, vector<int> result, vector<vector<int> > &ans)
    {
        if(depth == 0)
        {
            ans.push_back(result);
            return ;
        }
        for(int i = num; i <= max_num; ++i)
        {
            result.push_back(i);
            DFS(i + 1, max_num, depth - 1, result, ans);
            result.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        vector<vector<int> > ans;
        DFS(1, n, k, result, ans);
        return ans;
    }
};
