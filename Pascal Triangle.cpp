class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if(numRows == 0)
            return ans;
        vector<int> one;
        one.push_back(1);
        ans.push_back(one);
        int now = 0, next = 1;
        while(next <= numRows - 1)
        {
            vector<int> row;
            for(int i = 0; i < next + 1; ++i)
            {
                if(i == 0 || i == next)
                    row.push_back(1);
                else
                    row.push_back(ans[now][i] + ans[now][i - 1]);
            }
            ans.push_back(row);
            ++now;
            ++next;
        }
        return ans;
    }
};
