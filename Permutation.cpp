class Solution {
public:
    void DFS(int depth, int size, vector<bool> &hash, vector<int> num, vector<int> &result, vector<vector<int> > &ans)
    {
        if(depth==size)
        {
            ans.push_back(result);
            return ;
        }
        for(int i=0;i<size;i++)
        {
            if(hash[i]==false)
            {
                result[depth]=num[i];
                hash[i]=true;
                DFS(depth+1, size, hash, num, result, ans);
                hash[i]=false;
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> result;
        vector<bool> hash;
        if(num.size()==0)
            return ans;
        int size=num.size();
        for(int i=0;i<size;i++)
        {
            result.push_back(0);
            hash.push_back(false);
        }
        sort(num.begin(), num.end());
        DFS(0, size, hash, num, result, ans);
        return ans;
    }
};
