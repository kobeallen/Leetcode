class Solution {
public:
    void DFS(int depth, int size, vector<bool> &hash, vector<int> num, vector<int> &result, vector<vector<int> > &ans)
    {
        if(depth==size)
        {
            ans.push_back(result);
            return ;
        }
        int left=0, right;
        while(left<size)
        {
            if(hash[left]==false)
            {
                result[depth]=num[left];
                hash[left]=true;
                DFS(depth+1, size, hash, num, result, ans);
                hash[left]=false;
                right=left+1;
                while(right<size&&num[left]==num[right])
                    right++;
                left=right;
            }
            else
                left++;
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> result;
        vector<bool> hash;
        if(num.size()==0)
            return ans;
        sort(num.begin(), num.end());
        int size=num.size();
        result.resize(size);
        for(int i=0;i<size;i++)
            hash.push_back(false);
        DFS(0, size, hash, num, result, ans);
        return ans;
    }
};
