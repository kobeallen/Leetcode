class Solution {
public:
    void DFS(int pos, int depth, vector<int> array, vector<int> result, vector<vector<int> > &ans)
    {
        if(depth == 0)
        {
            ans.push_back(result);
            return ;
        }
        while(pos < array.size())
        {
            result.push_back(array[pos]);
            DFS(pos+1, depth-1, array, result, ans);
            result.pop_back();
            ++pos;
            while(pos < array.size() && array[pos] == array[pos-1])
                pos++;                
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<int> result;
        vector<vector<int> > ans;
        ans.push_back(result);
        for(int i = 1; i <= S.size(); ++i)
        {
            DFS(0, i, S, result, ans);
        }
        return ans;
    }
};