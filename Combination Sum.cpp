class Solution {
public:
    void DFS(int id, int target, vector<int> num, vector<int> &result, vector<vector<int> > &ans)
    {
        if(target==0)
        {
            ans.push_back(result);
            return ;
        }
        for(int i=id;i<num.size();i++)
        {
            if(target-num[i]>=0)
            {
                result.push_back(num[i]);
                DFS(i, target-num[i], num, result, ans);
                result.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        DFS(0, target, candidates, result, ans);
        return ans;
    }
};
