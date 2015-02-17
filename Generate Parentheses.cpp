class Solution {
public:
    void DFS(int depth, int count, int left_pa, int right_pa, string &result, vector<string> &ans)
    {
        if(left_pa==0&&right_pa==0)
        {
            ans.push_back(result);
            return ;
        }
        if(left_pa>0)
        {
            result[depth]='(';
            DFS(depth+1, count+1, left_pa-1, right_pa, result, ans);
        }
        if(right_pa>0&&count>0)
        {
            result[depth]=')';
            DFS(depth+1, count-1, left_pa, right_pa-1, result, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        vector<string> ans;
        result.resize(2*n);
        DFS(0, 0, n, n, result, ans);
        return ans;
    }
};

class Solution {
public:
    void DFS(int depth, int max_depth, int left_bracket, int right_bracket, string &result, vector<string> &ans)
    {
        if(depth == max_depth)
        {
            ans.push_back(result);
            return ;
        }
        if(left_bracket < max_depth / 2)
        {
            result[depth] = '(';
            DFS(depth + 1, max_depth, left_bracket + 1, right_bracket, result, ans);
        }
        if(left_bracket > right_bracket)
        {
            result[depth] = ')';
            DFS(depth + 1, max_depth, left_bracket, right_bracket + 1, result, ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        string result(2*n, ' ');
        DFS(0, 2*n, 0, 0, result, ans);
        return ans;
    }
};
