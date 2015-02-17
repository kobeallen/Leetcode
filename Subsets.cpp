class Solution {
public:
    void DFS(int id, int depth, int length, vector<int> S, vector<int> &result, vector<vector<int> > &ans)
    {
        if(depth==length)
        {
            ans.push_back(result);
            return ;
        }
        if(id==S.size())
            return ;
        for(int i=id;i<S.size();i++)
        {
            result[depth]=S[i];
            DFS(i+1, depth+1, length, S, result, ans);
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> result;
        ans.push_back(result);
        if(S.size()==0)
            return ans;
        int i, num=S.size();
        for(i=1;i<=num;i++)
        {
            result.resize(i);
            DFS(0, 0, i, S, result, ans);
        }
    }
};

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<int> result;
        vector<vector<int> > ans;
        if(S.empty())
            return ans;
        int size = S.size();
        int num = 1 << size;
        for(int i = 0; i < num; ++i)
        {
            result.clear();
            int index = 0, tmp = i;
            while(tmp > 0)
            {
                if(tmp % 2 == 1)
                    result.push_back(S[index]);
                ++index;
                tmp = tmp >> 1;
            }
            ans.push_back(result);
        }
        return ans;
    }
};