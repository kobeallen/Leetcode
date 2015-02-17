class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = triangle.size();
        if(size == 0)
            return 0;
        int sum[2][size];
        sum[0][0] = triangle[0][0];
        int now = 0, next = 1;
        int row = 1;
        while(row < triangle.size())
        {
            int left = 10000, right = 10000;
            for(int i = 0; i < triangle[row].size(); ++i)
            {
                if(i != 0)
                    left = sum[now][i - 1];
                if(i != triangle[row].size() - 1)
                    right = sum[now][i];
                int min = left < right ? left : right;
                sum[next][i] = min + triangle[row][i];
            }
            now = (now + 1) % 2;
            next = (next + 1) % 2;
            ++row;
        }
        int ans = 100000;
        for(int i = 0; i < triangle[row - 1].size(); ++i)
        {
            if(sum[now][i] < ans)
                ans = sum[now][i];
        }
        return ans;
    }
};
